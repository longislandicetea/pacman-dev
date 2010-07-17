#include "Fruit.h"
#include "Application.h"
#include <hge.h>
#include <hgeresource.h>
#include <hgesprite.h>
#include <cstdlib>

Fruit::Fruit( float x , float y ) :Bean(x,y)
{
	hge = Application::Inst()->Hge();
	spr = Application::Inst()->resMan()->GetSprite("Fruit");
	posx = x;
	posy = y;
	score = 100;
}

Fruit::~Fruit()
{

}