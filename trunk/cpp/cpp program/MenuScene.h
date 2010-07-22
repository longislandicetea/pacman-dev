#pragma once
#include <hge.h>
#include <hgefont.h>
#include <hgegui.h>
#include <hgesprite.h>
#include <hgeresource.h>
#include "IScene.h"

class MenuScene : public IScene
{
public:
	MenuScene();
	virtual bool FrameFunc();
	virtual bool RenderFunc();
	~MenuScene();
private:
	hgeGUI *guiMenu;
	HGE *hge;
	HEFFECT snd;
	hgeSprite* background;
	hgeSprite *spr;
	hgeFont *fnt;
	hgeResourceManager *manager;
};