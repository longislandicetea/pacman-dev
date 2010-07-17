#include "Monster.h"
#include "MovableObject.h"
#include "Application.h"
#include <hgeresource.h>
#include "MonsterAI.h"

Monster::Monster(Map *map,const char* sprname):MovableObject(100,0,0)
{
	hge = Application::Inst()->Hge();
	spr = Application::Inst()->resMan()->GetSprite(sprname);
	newSpr = Application::Inst()->resMan()->GetSprite("NewMonster");
	ai = new MonsterAI(map);
	sprName = sprname;
	score = 200;
	weakTime = 0.0f;
}

Monster::~Monster()
{
	delete ai;
}

void Monster::Update( float delta )
{
	if (weakTime > 0.0f) 
	{
		weakTime -= delta;
		if (weakTime <= 0.0f) {
			speed *= 2;
			weakTime = 0.0f;
		}
	}
	ai->Action(this,delta);
}

void Monster::Render()
{
	if (weakTime > 0.0f)
		newSpr->Render(posx , posy);
	else 
		spr->Render(posx,posy);
}

hgeRect* Monster::GetBoudingBox()
{
	hgeRect *rect = new hgeRect();
	return spr->GetBoundingBox(posx,posy,rect);
}

void Monster::SetPos( float x , float y )
{
	posx = x;
	posy = y;
}

void Monster::SetWeak( float time )
{
	if (weakTime == 0.0f)
		speed /= 2;
	weakTime = time;
}