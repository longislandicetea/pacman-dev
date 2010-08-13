#pragma once
#include "IScene.h"
#include <hge.h>

class hgeSprite;

class EndScene : public IScene
{
public:
	EndScene(bool _win);
	virtual bool FrameFunc();
	virtual bool RenderFunc();
private:
	hgeSprite *spr;
	HCHANNEL backSnd;
	int span;
	bool win;
};