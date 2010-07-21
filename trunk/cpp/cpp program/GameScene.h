#pragma once
#include <vector>
#include <hgefont.h>
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
	int GetOffset();
	~GameScene();
private:
	bool paused;
	Player *player;
	Map *gameMap;
	hgeFont *fnt;
	hgeFont *pauseFnt;
	int offset;
};