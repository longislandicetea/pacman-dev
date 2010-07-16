#pragma once
#include "IGameObject.h"
#include <hge.h>
#include <hgesprite.h>

class Bean:public IGameObject
{
public:
	Bean(float x , float y);
	virtual ~Bean();
	virtual void Update(float delta);
	virtual void Render();
	float Time() const { return time; }
	hgeRect* GetBoundingBox();
protected:
	hgeSprite *spr;
	HGE *hge;
	float posx;
	float posy;
	float time;
};