#include "Bean.h"
#include "Application.h"
#include <hgeresource.h>

void Bean::Init(float x , float y)
{
	hge = Application::Inst()->Hge();
	spr = Application::Inst()->resMan()->GetSprite("Bean");
	posX = x;
	posY = y;
	score = 10;
}

Bean::Bean( float x , float y )
{
	Init(x,y);
}

Bean::Bean( float x , float y , int _score , hgeSprite* _spr )
{
	Init(x,y);
	spr = _spr;
	score = _score;
}

void Bean::Render()
{
	spr->Render(posX,posY);
}

hgeRect* Bean::GetBoundingBox()
{
	hgeRect *rect = new hgeRect();
	return spr->GetBoundingBoxEx(posX,posY,0.0f,0.2f,0.2f,rect);
}

int Bean::GetScore()
{
	return score;
}

hgeSprite* Bean::GetSpr()
{
	return spr;
}