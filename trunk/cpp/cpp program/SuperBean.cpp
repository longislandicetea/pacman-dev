#include "SuperBean.h"
#include "Application.h"
#include <hgeresource.h>

SuperBean::SuperBean( float x , float y ) : Bean(x,y,50,Application::Inst()->resMan()->GetAnimation("SuperBean"))
{
	time = 10.0f;
	score = 50;
}

float SuperBean::Time() const
{
	return time;
}
