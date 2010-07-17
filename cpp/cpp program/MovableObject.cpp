#include "MovableObject.h"

float MovableObject::Speed()
{
	return speed;
}

void MovableObject::Up(float len)
{
	posy-=len*speed;
}

void MovableObject::Down(float len)
{
	posy+=len*speed;
}

void MovableObject::Left(float len)
{
	posx-=len*speed;
}

void MovableObject::Right(float len)
{
	posx+=len*speed;
}

MovableObject::MovableObject( float _speed , float _posx , float _posy )
{
	speed=_speed;
	posx=_posx;
	posy=_posy;
}

MovableObject::~MovableObject()
{

}