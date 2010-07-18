#include "SuperBean.h"
#include "Application.h"
#include <hgeresource.h>

SuperBean::SuperBean( float x , float y ) : Bean(x,y,50,Application::Inst()->resMan()->GetAnimation("SuperBean"))
{
	time = 10.0f;
	if (!(((hgeAnimation*)this->GetSpr())->IsPlaying()))
		((hgeAnimation*)this->GetSpr())->Play();
}

SuperBean::~SuperBean()
{

}

void SuperBean::Update( float delta )
{
	((hgeAnimation*)this->GetSpr())->Update(delta);
}
