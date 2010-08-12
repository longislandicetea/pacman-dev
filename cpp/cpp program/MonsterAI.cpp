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
	hgeRect *rc = monster->GetBoudingBox();

	if(map->IsCollide(*rc))
	{
		monster->SetPos(oldx,oldy);
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
