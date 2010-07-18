#include "MonsterAI.h"
#include "Monster.h"
#include "GameScene.h"
#include "Map.h"
#include <cstdlib>

MonsterAI::MonsterAI(Map *map)
{
	this->map=map;
}

void MonsterAI::Action(Monster* rhs , float delta)
{
	float oldx = rhs->PosX();
	float oldy = rhs->PosY();
	hgeRect *rc = rhs->GetBoudingBox();

	srand(12345);
	int directionNo = rand()%2;
	SetDirection(rhs);

	switch(directionNo)
	{
	case 0:
		{
			if(direction[directionNo]==2)
				rhs->Right(delta);
			else
				rhs->Left(delta);
			break;
		}
	case 1:
		{
			if(direction[directionNo]==0)
				rhs->Up(delta);
			else
				rhs->Down(delta);
		}
	}
	
	if (map->IsCollide(*rc)) 
	{
		rhs->SetPos(oldx,oldy);
		SetDirection(rhs);
	}
	delete rc;
}

void MonsterAI::SetDirection( Monster* rhs )
{
	float tx = map->PlayerX();
	float ty = map->PlayerY();

	if(tx<rhs->PosX())
		direction[0] = 3;
	else
		direction[0] = 2;

	if(ty<rhs->PosY())
		direction[1] = 1;
	else
		direction[1] = 0;
}