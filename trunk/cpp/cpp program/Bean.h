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
	int GetScore();
	hgeSprite* GetSpr();
	hgeRect* GetBoundingBox();
protected:
	Bean(float x , float y , int score , hgeSprite* spr);
private:
	void Init(float  x , float y);
	hgeSprite *spr;
	HGE *hge;
	int score;
	float posX;
	float posY;
};