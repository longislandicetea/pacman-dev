#pragma once
#include "IScene.h"
#include <hge.h>

class hgeFont;
class hgeGUI;
class hgeSprite;
class hgeResourceManager;

class MenuScene : public IScene
{
public:
	MenuScene();
	~MenuScene();
	virtual bool FrameFunc();
	virtual bool RenderFunc();
	//static HCHANNEL GetThemeMusic();
private:
	hgeGUI *guiMenu;
	HGE *hge;
	HEFFECT snd;
	//static HCHANNEL channel;
	hgeSprite *background;
	hgeSprite *spr;
	hgeFont *fnt;
	hgeResourceManager *manager;
};