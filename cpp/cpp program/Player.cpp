#include "Player.h" 
#include "Application.h"
#include <hge.h>
#include <hgesprite.h>
#include <hgeresource.h>
#include "GameScene.h"
#include "Map.h"

Player::Player(GameScene* scene) : MovableObject(80,0,0)
{

	hge = Application::Inst()->Hge();
	spr = Application::Inst()->resMan()->GetAnimation("Player");
	spr->Play();
	gameScene = scene;
	posX = scene->GetMap()->PlayerX();
	posY = scene->GetMap()->PlayerY();
	begX = posX;
	begY = posY;
	score = 0;
	life = 3;
	reviveTime = 0;
	rotation = 0.0f;
}

void Player::Render()
{
	spr->RenderEx(posX,posY,rotation);
}

void Player::Update(float delta)
{
	if (reviveTime > 0)
		--reviveTime;
	float length = delta;
	float oldx = posX , oldy = posY;
	
	if (hge->Input_GetKeyState(HGEK_LEFT)) 
	{
		Left(length);
		rotation = M_PI;
	}
	else if (hge->Input_GetKeyState(HGEK_RIGHT)) 
	{
		Right(length);
		rotation = 0.0f;
	}
	else if (hge->Input_GetKeyState(HGEK_UP))
	{
		Up(length);
		rotation = M_PI*1.5f;
	}
	else if (hge->Input_GetKeyState(HGEK_DOWN)) 
	{
		Down(length);
		rotation = M_PI/2.0f;
	}
	
	hgeRect* rc = this->GetBoundingBox();
	if (gameScene->GetMap()->IsCollide(*rc)) 
	{
		posX = oldx;
		posY = oldy;
	}
	spr->Update(delta);
	gameScene->GetMap()->Eat(rc);
	gameScene->GetMap()->CheckAndEat(rc);
	delete rc;
}

Player::~Player()
{
}

hgeRect* Player::GetBoundingBox()
{
	hgeRect *rect = new hgeRect();
	return spr->GetBoundingBoxEx(posX,posY,0.0f,0.8f,0.8f,rect);
}


void Player::AddScore( int added )
{
	score += added;
}

void Player::SetLife()
{
	if(life>0)
		--life;
}

int Player::GetLife()
{
	return life;
}

void Player::SetPos( float x, float y )
{
	posX = x;
	posY = y;
}

float Player::BegX() const
{
	return begX;
}

float Player::BegY() const
{
	return begY;
}

int Player::GetScore()
{
	return score;
}

void Player::Revive()
{
	reviveTime = 120;
}

bool Player::CanEat() const
{
	return reviveTime == 0;
}