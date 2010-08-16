#include "MonsterAI.h"
#include "Monster.h"
#include "GameScene.h"
#include "Map.h"
#include <cstdlib>
#include "Player.h"
#include "GameScene.h"

MonsterAI::MonsterAI(Map *map)
{
	this->map=map;
	direction = rand()%4;
	collidTimes = 0;
	aiState = 0;//use normalAI at beginning
}

void MonsterAI::Action(Monster *monster , float delta)
{
	float oldX = monster->PosX();
	float oldY = monster->PosY();
	move(monster,delta);

	if(collidTimes>3)
		aiState = (aiState+1)%2;

	switch(aiState)
	{
	case'0':{
		if(handleCollide(monster,oldX,oldY))
			normalAI(direction);
			}
	case'1':{
		if(handleCollide(monster,oldX,oldY))
			smartAI(oldX,oldY,direction);
			}
	}
}

void MonsterAI::normalAI( int now )
{
	do 
	{
		direction = rand()%4;
	} while (direction==now);
}

void MonsterAI::randDirection( int x , int y )
{
	int d[2];
	d[0] = x;
	d[1] = y;
	direction = d[rand()%2];
}

void MonsterAI::smartAI( float monsterX , float monsterY,int now)
{
	float playerX = map->GetGameScene()->GetPlayer()->PosX();
	float playerY = map->GetGameScene()->GetPlayer()->PosY();

	if (monsterX<playerX && monsterY<playerY)
		randDirection(1,3);
	else if (monsterX>playerX && monsterY<playerY)
		randDirection(1,2);
	else if (monsterX<playerX && monsterY>playerY)
		randDirection(0,3);
	else if (monsterX>playerX && monsterY>playerY)
		randDirection(0,2);
}

void MonsterAI::move( Monster *monster,float delta )
{
	float oldx = monster->PosX();
	float oldy = monster->PosY();
	switch (direction)
	{
	case 0:
		monster->Up(delta);
		break;
	case 1:
		monster->Down(delta);
		break;
	case 2:
		monster->Left(delta);
		break;
	case 3:
		monster->Right(delta);
		break;
	}
}

bool MonsterAI::handleCollide( Monster* monster,float x,float y )
{
	hgeRect *rc = monster->GetBoudingBox();
	if(map->IsCollide(*rc))
	{
		monster->SetPos(x,y);
		++collidTimes;
		delete rc;
		return true;
	}
	else 
	{
		delete rc;
		return false;
	}
}
