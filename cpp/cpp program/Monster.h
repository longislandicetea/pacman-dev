#pragma once
#include "MovableObject.h"
#include "GameScene.h"
#include <hgesprite.h>
#include <hge.h>

class MonsterAI;

class Monster:public MovableObject
{
public:
	Monster(Map *map);
	~Monster();
	virtual void Update(float delta);
	virtual void Render();
	void SetPos(float x , float y);
	hgeRect* GetBoudingBox();
private:
	hgeSprite *spr;
	HGE *hge;
	MonsterAI *ai;
};