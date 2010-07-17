#include "Player.h" 
#include "Application.h"
#include <hge.h>
#include <hgesprite.h>
#include <hgeresource.h>
#include "GameScene.h"
#include "Map.h"

Player::Player(GameScene* scene) : MovableObject(100,0,0)
{

	hge = Application::Inst()->Hge();
	spr = Application::Inst()->resMan()->GetSprite("Player");
	gameScene = scene;
	posx = scene->GetMap()->PlayerX();
	posy = scene->GetMap()->PlayerY();
	begX = posx;
	begY = posy;
	score = 0;
	life = 3;
}

void Player::Render()
{
	spr->Render(posx,posy);
}

void Player::Update(float delta)
{
	float length = delta;
	float oldx = posx , oldy = posy;
	if (hge->Input_GetKeyState(HGEK_LEFT)) Left(length);
	if (hge->Input_GetKeyState(HGEK_RIGHT)) Right(length);
	if (hge->Input_GetKeyState(HGEK_UP)) Up(length);
	if (hge->Input_GetKeyState(HGEK_DOWN)) Down(length);
	hgeRect* rc = this->GetBoundingBox();
	if (gameScene->GetMap()->IsCollide(*rc)) 
	{
		posx = oldx;
		posy = oldy;
	}
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
	return spr->GetBoundingBox(posx,posy,rect);
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
	posx = x;
	posy = y;
}

float Player::BegX()
{
	return begX;
}

float Player::BegY()
{
	return begY;
}