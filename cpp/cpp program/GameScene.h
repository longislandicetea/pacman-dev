#pragma once
#include <vector>
#include <hgefont.h>
#include <hge.h>
#include "IScene.h"

class Map;
class Monster;
class Player;

class GameScene : public IScene
{
public:
	GameScene();
	virtual bool FrameFunc();
	virtual bool RenderFunc();
	Map* GetMap();
	Player* GetPlayer();
	HEFFECT* GetEatSnd();
	int GetOffset();
	~GameScene();
private:
	bool paused;
	Player *player;
	Map *gameMap;
	hgeFont *fnt;
	hgeFont *pauseFnt;
	HEFFECT eatSnd;
};