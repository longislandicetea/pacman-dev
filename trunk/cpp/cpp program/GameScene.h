#pragma once
#include <vector>
#include <hge.h>
#include "IScene.h"

class Map;
class Monster;
class Player;
class hgeFont;

class GameScene : public IScene
{
public:
	GameScene();
	~GameScene();
	virtual bool FrameFunc();
	virtual bool RenderFunc();
	Map* GetMap();
	Player* GetPlayer();
	HEFFECT* GetEatSnd();
	int GetOffset();
private:
	bool paused;
	Player *player;
	Map *gameMap;
	hgeFont *fnt;
	hgeFont *pauseFnt;
	HEFFECT eatSnd;
};