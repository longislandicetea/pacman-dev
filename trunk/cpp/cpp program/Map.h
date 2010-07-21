#pragma once
#include <hgerect.h>
#include <hge.h>
#include <hgesprite.h>
#include <vector>
#include <string>
#include "IGameObject.h"

class Bean;
class Monster;
class GameScene;
class EndScene;

struct RecoverInfo
{
	std::string recoverSprName;
	float recoverMinute;
};

class Fruit;

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
	void UpdateSuperBean(float dt);
	float PlayerX() const { return playerX; }
	float PlayerY() const { return playerY;}
	void SetFruit(float delta);
private:
	typedef std::vector<Monster*> MonsterContainer;
	std::vector<hgeRect*> walls;
	std::vector<Bean*> beans;
	MonsterContainer monsters;
	float playerX,playerY;
	float fruitX,fruitY;
	int length,width;
	float sideLen;
	float fruitTime;
	Fruit *fruit;
	hgeSprite *wallSpr;
	GameScene *gameScene;
	EndScene * endScene;
	HGE *hge;
};