#pragma once
#include <hgerect.h>
#include <hge.h>
#include <hgesprite.h>
#include <vector>
#include "IGameObject.h"

class Bean;
class Monster;
class GameScene;
class Map : IGameObject
{
public:
	Map(GameScene *scene);
	~Map();
	virtual void Update(float dt);
	virtual void Render();
	void SetMap(char *filename);
	bool IsCollide(hgeRect& rhs);
	void Eat(hgeRect *rc);
	void CheckAndEat(hgeRect *rc);
	float PlayerX() const { return playerX; }
	float PlayerY() const { return playerY; }
private:
	std::vector<hgeRect*> walls;
	std::vector<Bean*> beans;
	std::vector<Monster*> monsters;
	float playerX,playerY;
	int length,width;
	float sideLen;
	hgeSprite *wallSpr;
	hgeSprite *beanSpr;
	GameScene *gameScene;
	HGE *hge;
};