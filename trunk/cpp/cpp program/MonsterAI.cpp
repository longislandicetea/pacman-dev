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
}

void MonsterAI::Action(Monster *monster , float delta)
{
	float oldx = monster->PosX();
	float oldy = monster->PosY();
	
	//set direction at random
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
	
	if(collidTimes>3)
	{
		collidTimes = 0;
		normalAI(direction);
	}
	else
		smartAI(monster->PosX(),monster->PosY(),direction);
	
	hgeRect *rc = monster->GetBoudingBox();
	if(map->IsCollide(*rc))
	{
		monster->SetPos(oldx,oldy);
		normalAI(direction);
		++collidTimes;
	}
	delete rc;
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
