#include "Fruit.h"
#include "Application.h"
#include <hge.h>
#include <hgeresource.h>
#include <hgesprite.h>
#include <cstdlib>

Fruit::Fruit( float x , float y ) :Bean(x,y,200 ,Application::Inst()->resMan()->GetSprite("Fruit"))
{
	score = 100;
}

Fruit::~Fruit()
{

}