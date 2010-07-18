#include "Bean.h"
#include "Application.h"
#include <hgeresource.h>

Bean::Bean( float x , float y )
{
	hge = Application::Inst()->Hge();
	spr = Application::Inst()->resMan()->GetSprite("Bean");
	posX = x;
	posY = y;
	score = 10;
}

Bean::Bean( float x , float y , int _score , hgeSprite* _spr )
{
	Bean(x , y);
	spr = _spr;
	score = _score;
}
void Bean::Update( float delta )
{

}

void Bean::Render()
{
	spr->Render(posX,posY);
}

hgeRect* Bean::GetBoundingBox()
{
	hgeRect *rect = new hgeRect();
	return spr->GetBoundingBox(posX,posY,rect);
}

Bean::~Bean()
{

}

int Bean::GetScore()
{
	return score;
}

hgeSprite* Bean::GetSpr()
{
	return spr;
}