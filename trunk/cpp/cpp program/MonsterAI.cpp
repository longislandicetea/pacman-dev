#include "MonsterAI.h"
#include "Monster.h"
#include "GameScene.h"
#include "Map.h"
#include <cstdlib>

MonsterAI::MonsterAI(Map *map)
{
	srand(12345);
	direction = rand() % 4;
	this->map=map;
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
		rhs->Right(delta);
		break;
	case 3:
		rhs->Left(delta);
		break;
	}
	hgeRect *rc = rhs->GetBoudingBox();
	if (map->IsCollide(*rc)) 
	{
		rhs->SetPos(oldx,oldy);
		direction = rand() % 4;
	}
	delete rc;
}