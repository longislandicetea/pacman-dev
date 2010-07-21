#pragma once
#include "IScene.h"
#include <hgefont.h>
#include <hgesprite.h>

class EndScene : public IScene
{
public:
	EndScene(bool _win);
	virtual bool FrameFunc();
	virtual bool RenderFunc();
private:
	hgeFont *fnt;
	hgeSprite *spr;
	int span;
	bool win;
};