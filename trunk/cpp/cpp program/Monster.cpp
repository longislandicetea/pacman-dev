#include "Monster.h"
#include "MovableObject.h"
#include "Application.h"
#include <hgeresource.h>
#include "MonsterAI.h"

Monster::Monster(Map *map , const char *sprname , float _originX , float _originY):MovableObject(80,0,0)
{
	hge = Application::Inst()->Hge();
	spr = Application::Inst()->resMan()->GetSprite(sprname);
	newSpr = Application::Inst()->resMan()->GetSprite("NewMonster");
	ai = new MonsterAI(map);
	sprName = sprname;
	score = 200;
	weakTime = 0.0f;
	deathTime = 0;
	posX = originX = _originX;
	posY = originY = _originY;
}

Monster::~Monster()
{
	delete ai;
}

void Monster::Update( float delta )
{
	if (deathTime > 0) {
		--deathTime;
		return;
	}

	if (weakTime > 0.0f) 
	{
		weakTime -= delta;
		if (weakTime <= 0.0f) 
		{
			speed *= 2;
			weakTime = 0.0f;
		}
	}

	ai->Action(this,delta);
}

void Monster::Render()
{
	if (deathTime > 0)
		return;

	if (weakTime > 0.0f)
		newSpr->Render(posX , posY);
	else 
		spr->Render(posX,posY);
}

hgeRect* Monster::GetBoudingBox()
{
	hgeRect *rect = new hgeRect();
	return spr->GetBoundingBoxEx(posX,posY,0.0f,0.8f,0.8f,rect);
}

void Monster::SetWeak( float time )
{
	if (weakTime == 0.0f)
		speed /= 2;
	weakTime = time;
}

MonsterAI* Monster::GetAI()
{
	return ai;
}

void Monster::SetOrigin()
{
	posX = originX;
	posY = originY;
}

bool Monster::IsWeak() const
{
	return weakTime > 0.0f;
}

const std::string& Monster::SprName() const
{
	return sprName;
}

bool Monster::IsAlive() const
{
	return deathTime == 0;
}

void Monster::DeathTime( int val )
{
	deathTime = val;
	weakTime = 0.0f;
}
