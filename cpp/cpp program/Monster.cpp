#include "Monster.h"
#include "MovableObject.h"
#include "Application.h"
#include <hgeresource.h>
#include "MonsterAI.h"

Monster::Monster(Map *map,const char* sprname):MovableObject(100,0,0)
{
	hge = Application::Inst()->Hge();
	spr = Application::Inst()->resMan()->GetSprite(sprname);
	ai=new MonsterAI(map);
	sprName = sprname;
	score = 200;
}

Monster::~Monster()
{
	delete ai;
}

void Monster::Update( float delta )
{
	ai->Action(this,delta);
}

void Monster::Render()
{
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