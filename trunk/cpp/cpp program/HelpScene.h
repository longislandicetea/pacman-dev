#pragma once

#include "IScene.h"
#include <hge.h>
#include <hgeresource.h>

class hgeFont;
class hgeSprite;
class hgeGUI;

class HelpScene : public IScene
{
public:
	HelpScene();
	~HelpScene();
	virtual bool FrameFunc();
	virtual bool RenderFunc();
private:
	hgeGUI *guiHelp;
	HGE *hge;
	HEFFECT snd;
	hgeSprite *background;
	hgeSprite *spr;
	hgeFont *fnt;
	hgeResourceManager *manager;
};