#pragma once
#include "MovableObject.h"
#include <string>

class HGE;
class hgeSprite;
class hgeRect;
class MonsterAI;
class Map;

class Monster:public MovableObject
{
public:
	Monster(Map *map , const char *sprname , float originX , float originY);
	~Monster();
	virtual void Update(float delta);
	virtual void Render();
	const std::string& SprName() const;
	bool IsWeak() const;
	bool IsAlive() const;
	hgeRect* GetBoudingBox();
	MonsterAI* GetAI();
	void SetWeak(float time);
	void SetOrigin();
	void DeathTime(int val);
private:
	float weakTime;
	float originX,originY;
	int deathTime;
	hgeSprite *spr;
	int score;
	hgeSprite *newSpr;
	HGE *hge;
	MonsterAI *ai;
	std::string sprName;
};