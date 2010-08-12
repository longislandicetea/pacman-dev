#pragma once
#include "IScene.h"

class hgeSprite;

class EndScene : public IScene
{
public:
	EndScene(bool _win);
	virtual bool FrameFunc();
	virtual bool RenderFunc();
private:
	hgeSprite *spr;
	int span;
	bool win;
};