#include "MovableObject.h"

int IGameObject::GetScore()
{
	return score;
}

float IGameObject::PosX()
{
	return posX;
}

float IGameObject::POSy()
{
	return posY;
}

void IGameObject::SetPos( float x , float y )
{
	posX = x;
	posY = y;
}