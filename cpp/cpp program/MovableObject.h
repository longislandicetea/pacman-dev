#pragma once
#include "IGameObject.h"

class MovableObject:public IGameObject
{
public:
	MovableObject(float speed , float posx , float posy);
	virtual void Update(float delta) =0;
	virtual void Render() =0;
	float Speed() const;
	void Up(float len);
	void Down(float len);
	void Left(float len);
	void Right(float len);
	float PosX() const; 
	float PosY() const; 
	void SetPos(float x , float y);
protected:
	float speed;
	float posX;
	float posY;
};