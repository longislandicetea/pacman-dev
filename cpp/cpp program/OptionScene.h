#pragma once

#include "IScene.h"
#include <hge.h>
#include <hgeresource.h>

class hgeFont;
class hgeSprite;
class hgeGUI;

class OptionScene : public IScene
{
public:
	OptionScene();
	~OptionScene();
	virtual bool FrameFunc();
	virtual bool RenderFunc();
private:
	hgeGUI *guiOption;
	HGE *hge;
	HEFFECT snd;
	hgeSprite *background;
	hgeSprite *spr;
	hgeFont *fnt;
	hgeResourceManager *manager;
};