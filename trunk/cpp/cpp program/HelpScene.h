#pragma once
#include <hge.h>
#include <hgefont.h>
#include <hgesprite.h>
#include <hgeresource.h>
#include <hgegui.h>
#include "IScene.h"

class HelpScene : public IScene
{
public:
	HelpScene();
	virtual bool FrameFunc();
	virtual bool RenderFunc();
	~HelpScene();
private:
	hgeGUI *guiHelp;
	HGE *hge;
	HEFFECT snd;
	hgeSprite* background;
	hgeSprite *spr;
	hgeFont *fnt;
	hgeResourceManager *manager;
};