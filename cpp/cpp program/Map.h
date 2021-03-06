#pragma once

#include <vector>
#include <string>
#include "IGameObject.h"

class Bean;
class Fruit;
class Monster;
class GameScene;
class EndScene;
class HGE;
class hgeRect;
class hgeFont;
class hgeSprite;

struct RecoverInfo
{
	std::string recoverSprName;
	float recoverMinute;
};

class Map : IGameObject
{
public:
	Map(GameScene *scene);
	~Map();
	virtual void Update(float dt);
	virtual void Render();
	bool IsCollide(hgeRect& rhs) const;
	float PlayerX() const;
	float PlayerY() const;
	GameScene* GetGameScene();
	void EatMonster(hgeRect *rc);
	void EatBean(hgeRect *rc);
	void UpdateSuperBean(float dt);
	void SetMap(char *filename);
	void UpdateFruit(float delta);
private:
	typedef std::vector<Monster*> monsterContainer;
	std::vector<hgeRect*> walls;
	std::vector<Bean*> beans;
	monsterContainer monsters;
	float playerX,playerY;
	float fruitX,fruitY;
	int length,width;
	float sideLen;
	float fruitTime;
	Fruit *fruit;
	hgeSprite *wallSpr;
	GameScene *gameScene;
	EndScene *endScene;
	hgeFont *fnt;
	HGE *hge;
};