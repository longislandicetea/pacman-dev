#include "Map.h"
#include<cstdio>
#include<vector>
#include <hgeresource.h>
#include "hgerect.h"
#include "GameScene.h"
#include "Player.h"
#include "Monster.h"
#include "Bean.h"
#include "SuperBean.h"
#include "Application.h"
#pragma warning (disable: 4996)

Map::Map(GameScene *scene)
{
	hge = Application::Inst()->Hge();
	wallSpr = Application::Inst()->resMan()->GetSprite("Wall");
	beanSpr = Application::Inst()->resMan()->GetSprite("Bean");
	sideLen = 32;
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
				walls.push_back(tmprect);
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
				Monster* m = new Monster(this);
				m->SetPos(tmprect->x1,tmprect->y1);
				monsters.push_back(m);
			}
		}
		fscanf(fin,"\n");
	}
}

void Map::CheckAndEat( hgeRect *rc ) 
{
	for(int i=0;i<(int)beans.size();++i)
	{
		if(beans[i]->GetBoundingBox()->Intersect(rc))
		{
			if (typeid(*beans[i])==typeid(SuperBean)) 
			{
				gameScene->GetPlayer()->SetState(((SuperBean*)beans[i])->Time());
			}

			delete beans[i];
			beans.erase(beans.begin()+i);
		}
	}
}

void Map::Update( float dt )
{
	for(int i=0;i<(int)monsters.size();++i)
		monsters[i]->Update(dt);
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

void Map::Eat( hgeRect *rc )
{
	for(int i=0;i<(int)monsters.size();++i)
	{
		hgeRect* tmprect=monsters[i]->GetBoudingBox();
		if(rc->Intersect(tmprect))
		{
			if(fabs(gameScene->GetPlayer()->State())<1e-6)
			{
				//TODO
			}
			else
			{
				delete monsters[i];
				monsters.erase(monsters.begin()+i);
			}
		}
	}
}