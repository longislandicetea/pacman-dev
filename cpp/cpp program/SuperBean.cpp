#include "SuperBean.h"
#include "Application.h"
#include <hgeresource.h>

SuperBean::SuperBean( float x , float y ) : Bean(x,y)
{
	hge = Application::Inst()->Hge();
	spr = Application::Inst()->resMan()->GetSprite("SuperBean");
	posx = x;
	posy = y;
	time = 10.0f;
	score=50;
}

SuperBean::~SuperBean()
{

}