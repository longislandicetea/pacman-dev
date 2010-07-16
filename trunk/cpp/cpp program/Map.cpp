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
#include "GameScene.h"
#include "Player.h"
#include "Monster.h"
#include "Bean.h"
#include "SuperBean.h"
#include "Fruit.h"
#include "Application.h"
#pragma warning (disable: 4996)

Map::Map(GameScene *scene)
{
	hge = Application::Inst()->Hge();
	wallSpr = Application::Inst()->resMan()->GetSprite("Wall");
	beanSpr = Application::Inst()->resMan()->GetSprite("Bean");
	sideLen = 15;
	gameScene = scene;
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

void Map::SetMap( char* filename )
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
				Bean* b = new Fruit(tmprect->x1,tmprect->y1);
				beans.push_back(b);
			}
			delete tmprect;
		}
		fscanf(fin,"\n");
	}
}

void Map::CheckAndEat( hgeRect *rc ) 
{
	for(int i=0;i<(int)beans.size();++i)
	{
		hgeRect* brc = beans[i]->GetBoundingBox();
		bool isBean = true;
		if(brc->Intersect(rc))
		{
			if (typeid(*beans[i])==typeid(SuperBean)) 
			{
				gameScene->GetPlayer()->SetState(((SuperBean*)beans[i])->Time());
				gameScene->GetPlayer()->SetScore(50);
				isBean = false;
			}
			else if(typeid(*beans[i])==typeid(Fruit))
			{
				gameScene->GetPlayer()->SetState(((Fruit*)beans[i])->Time());
				gameScene->GetPlayer()->SetScore(100);
				isBean = false;
			}
			if(isBean)
				gameScene->GetPlayer()->SetScore(10);
			delete beans[i];
			beans.erase(beans.begin()+i);
		}
		delete brc;
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
	for(int i=0;i<(int)inserted.size();++i)
		inserted[i].recoverMinute-=dt;

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

void Map::Render()
{
	for(int i=0;i<(int)walls.size();++i)
		wallSpr->Render(walls[i]->x1,walls[i]->y1);
	for(int i=0;i<(int)beans.size();++i)
		beans[i]->Render();
	for(int i=0;i<(int)monsters.size();++i)
		monsters[i]->Render();
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
		if(rc->Intersect(tmprect))
		{
			if(fabs(gameScene->GetPlayer()->State())<1e-6)
			{
				//todo;
				gameScene->GetPlayer()->SetLife();
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
				gameScene->GetPlayer()->SetScore(200);
			}
		}
		++cur;
	}
	mIter newEnd = std::remove_if(monsters.begin(),monsters.end(),check);
	monsters.erase(newEnd,monsters.end());
}