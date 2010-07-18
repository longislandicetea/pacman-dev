#include "Map.h"
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <hgeresource.h>
#include <hgerect.h>
#include <hge.h>
#include <hgesprite.h>
#include <hgeanim.h>
#include "GameScene.h"
#include "Player.h"
#include "Monster.h"
#include "Bean.h"
#include "SuperBean.h"
#include "Fruit.h"
#include "Application.h"
#include "MenuScene.h"
#pragma warning (disable: 4996)

Map::Map(GameScene *scene)
{
	hge = Application::Inst()->Hge();
	wallSpr = Application::Inst()->resMan()->GetSprite("Wall");
	Application::Inst()->resMan()->GetAnimation("SuperBean")->Play();
	sideLen = 15;
	gameScene = scene;
	fruitTime = 2.0f;
	fruit = NULL;
}

Map::~Map()
{
	for(int i=0;i<(int)walls.size();++i)
		delete walls[i];
	for(int i=0;i<(int)beans.size();++i)
		delete beans[i];
	for(int i=0;i<(int)monsters.size();++i)
		delete monsters[i];
}

bool Map::IsCollide( hgeRect& rhs )
{
	for(int i=0;i<(int)walls.size();++i)
	{
		if(rhs.Intersect(walls[i]))
			return true;
	}
	return false;
}

void Map::SetMap( char *filename )
{
	FILE* fin = fopen(filename,"r");
	fscanf(fin,"%d%d\n",&length,&width);
	char tmpc;
	for(int i=0;i<length;++i)
	{
		for(int j=0;j<width;++j)
		{
			fscanf(fin,"%c",&tmpc);
			
			float posx = j*sideLen, posy = i*sideLen;
			hgeRect* tmprect = new hgeRect(posx,posy,posx+sideLen,posy+sideLen);
			if(tmpc=='X') 
			{
				walls.push_back(new hgeRect(*tmprect));
			}
			else if(tmpc=='P')
			{
				playerX = posx;
				playerY = posy;
			}
			else if(tmpc==' ')
			{
				Bean* b = new Bean(tmprect->x1,tmprect->y1);
				beans.push_back(b);
			} 
			else if (tmpc=='S')
			{
				Bean* b = new SuperBean(tmprect->x1,tmprect->y1);
				beans.push_back(b);
			}
			else if(tmpc=='M') 
			{
				Monster* m = new Monster(this,"Monster");
				monsterX = tmprect->x1;
				monsterY = tmprect->y1;
				m->SetPos(tmprect->x1,tmprect->y1);
				monsters.push_back(m);
			}
			else if(tmpc=='F')
			{
				fruitX = tmprect->x1;
				fruitY = tmprect->y1;
			}
			delete tmprect;
		}
		fscanf(fin,"\n");
	}
}

void Map::CheckAndEat( hgeRect *rc ) 
{
	for(int i = 0;i<(int)beans.size();++i)
	{
		hgeRect* brc = beans[i]->GetBoundingBox();
		if(brc->Intersect(rc))
		{
			gameScene->GetPlayer()->AddScore(beans[i]->GetScore());
			if (typeid(*beans[i])==typeid(SuperBean)) 
			{
				for(int j =0;j<(int)monsters.size();++j)
				{
					monsters[j]->SetWeak(((SuperBean*)beans[i])->Time());
				}
			}
			delete beans[i];
			beans.erase(beans.begin()+i);
		}
		delete brc;
	}
	if (fruit!=NULL) 
	{
		hgeRect *frc = fruit->GetBoundingBox();
		if (frc->Intersect(rc)) 
		{
			gameScene->GetPlayer()->AddScore(fruit->GetScore());
			delete fruit;
			fruit = NULL;
			fruitTime = 20.0f;
		}
	}
}

bool check2(const RecoverInfo &info) 
{
	return info.recoverMinute < -100.0f;
}

void Map::Update( float dt )
{
	for(int i=0;i<(int)monsters.size();++i)
		monsters[i]->Update(dt);

	for(int i=0;i<(int)beans.size();++i)
		beans[i]->Update(dt);

	UpdateSuperBean(dt);

	MonsterRevive(dt);

	SetFruit(dt);
}

void Map::Render()
{
	for(int i=0;i<(int)walls.size();++i)
		wallSpr->Render(walls[i]->x1,walls[i]->y1);

	for(int i=0;i<(int)beans.size();++i)
		beans[i]->Render();

	for(int i=0;i<(int)monsters.size();++i)
		monsters[i]->Render();

	if (fruit!=NULL)
		fruit->Render();
}

bool check(Monster* monster) 
{
	return monster == NULL;
}

void Map::Eat( hgeRect *rc )
{
	typedef MonsterContainer::iterator mIter;
	mIter cur = monsters.begin();
	
	while(cur != monsters.end()) 
	{
		hgeRect* tmprect=(*cur)->GetBoudingBox();
		Player* tmpplayer=gameScene->GetPlayer();
		if(rc->Intersect(tmprect))
		{
			if(!((*cur)->IsWeak()))
			{
				tmpplayer->SetLife();
				tmpplayer->SetPos(tmpplayer->BegX(),tmpplayer->BegY());
				if(tmpplayer->GetLife()==0)
				{
					Application::Inst()->ChangeScene(new MenuScene());
				}
			}
			else
			{
				const std::string& tn = (*cur)->SprName();
				RecoverInfo tmp;
				tmp.recoverSprName=tn;
				tmp.recoverMinute=1.0f;
				inserted.push_back(tmp);
				delete (*cur);
				*cur = NULL;
				tmpplayer->AddScore(200);
			}
		}
		++cur;
	}
	
	mIter newEnd = std::remove_if(monsters.begin(),monsters.end(),check);
	monsters.erase(newEnd,monsters.end());
}

void Map::UpdateSuperBean(float dt)
{
	Application::Inst()->resMan()->GetAnimation("SuperBean")->Update(dt);
}

void Map::MonsterRevive( float delta )
{
	for(int i=0;i<(int)inserted.size();++i)
		inserted[i].recoverMinute-=delta;

	for (int i = 0 ;i<(int)inserted.size();++i) 
	{
		if(inserted[i].recoverMinute<=0.0f) 
		{
			Monster *m = new Monster(this,inserted[i].recoverSprName.c_str());
			m->SetPos(monsterX,monsterY);
			monsters.push_back(m);
			inserted[i].recoverMinute = -1000.0f;
		}
	}

	std::vector<RecoverInfo>::iterator newEnd = std::remove_if(inserted.begin(),inserted.end(),check2);
	inserted.erase(newEnd,inserted.end());
}

void Map::SetFruit( float delta )
{
	if(fruitTime>0.0f)
		fruitTime -= delta;
	if (fruitTime<=0.0f)
	{
		if (fruit == NULL) 
		{
			fruit = new Fruit(fruitX,fruitY);
			fruitTime = 10.0f;
		} 
		else 
		{
			delete fruit;
			fruit = NULL;
			fruitTime = 20.0f;
		}
	}
}