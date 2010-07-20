#include "MonsterAI.h"
#include "Monster.h"
#include "GameScene.h"
#include "Map.h"
#include <cstdlib>

MonsterAI::MonsterAI(Map *map)
{
	this->map=map;
	direction = rand()%4;
}

void MonsterAI::Action(Monster* rhs , float delta)
{
	float oldx = rhs->PosX();
	float oldy = rhs->PosY();
	
	switch (direction)
	{
	case 0:
		rhs->Up(delta);
		break;
	case 1:
		rhs->Down(delta);
		break;
	case 2:
		rhs->Left(delta);
		break;
	case 3:
		rhs->Right(delta);
		break;
	}
	hgeRect *rc = rhs->GetBoudingBox();

	if(map->IsCollide(*rc))
	{
		rhs->SetPos(oldx,oldy);
		SetDirection(direction);
	}

	delete rc;
}

void MonsterAI::SetDirection( int now )
{
	do 
	{
		direction = rand()%4;
	} while (direction==now);
}
