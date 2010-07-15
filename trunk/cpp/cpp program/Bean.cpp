#include "Bean.h"
#include "Application.h"
#include <hgeresource.h>

Bean::Bean( float x , float y )
{
	hge = Application::Inst()->Hge();
	spr = Application::Inst()->resMan()->GetSprite("Bean");
	posx = x;
	posy = y;
}

void Bean::Update( float delta )
{

}

void Bean::Render()
{
	spr->Render(posx,posy);
}

hgeRect* Bean::GetBoundingBox()
{
	hgeRect *rect = new hgeRect();
	return spr->GetBoundingBox(posx,posy,rect);
}

Bean::~Bean()
{

}