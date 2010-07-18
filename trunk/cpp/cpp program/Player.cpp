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
	spr = Application::Inst()->resMan()->GetAnimation("Player");
	spr->Play();
	gameScene = scene;
	posX = scene->GetMap()->PlayerX();
	posY = scene->GetMap()->PlayerY();
	begX = posX;
	begY = posY;
	score = 0;
	life = 3;
}

void Player::Render()
{
	spr->Render(posX,posY);
}

void Player::Update(float delta)
{
	float length = delta;
	float oldx = posX , oldy = posY;
	if (hge->Input_GetKeyState(HGEK_LEFT)) Left(length);
	if (hge->Input_GetKeyState(HGEK_RIGHT)) Right(length);
	if (hge->Input_GetKeyState(HGEK_UP)) Up(length);
	if (hge->Input_GetKeyState(HGEK_DOWN)) Down(length);
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
	return spr->GetBoundingBox(posX,posY,rect);
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

float Player::BegX()
{
	return begX;
}

float Player::BegY()
{
	return begY;
}

int Player::GetScore()
{
	return score;
}