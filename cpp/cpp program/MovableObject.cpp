#include "MovableObject.h"

float MovableObject::Speed()
{
	return speed;
}

void MovableObject::Up(float len)
{
	posY-=len*speed;
}

void MovableObject::Down(float len)
{
	posY+=len*speed;
}

void MovableObject::Left(float len)
{
	posX-=len*speed;
}

void MovableObject::Right(float len)
{
	posX+=len*speed;
}

MovableObject::MovableObject( float _speed , float _posx , float _posy )
{
	speed=_speed;
	posX=_posx;
	posY=_posy;
}

void MovableObject::SetPos( float x , float y )
{
	posX = x;
	posY = y;
}