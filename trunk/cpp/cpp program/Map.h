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
	void SetMap(char *filename);
	bool IsCollide(hgeRect& rhs);
	void Eat(hgeRect *rc);
	void CheckAndEat(hgeRect *rc);
	float PlayerX() const { return playerX; }
	float PlayerY() const { return playerY;} 
private:
	typedef std::vector<Monster*> MonsterContainer;
	std::vector<hgeRect*> walls;
	std::vector<Bean*> beans;
	MonsterContainer monsters;
	std::vector<RecoverInfo> inserted;
	float playerX,playerY;
	int length,width;
	float monsterX , monsterY;
	float sideLen;
	hgeSprite *wallSpr;
	GameScene *gameScene;
	HGE *hge;
};