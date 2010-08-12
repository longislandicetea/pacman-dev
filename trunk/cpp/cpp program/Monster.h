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
	void SetOrigin();//the dead monster appears in the origin position
	void DeathTime(int val);
private:
	float weakTime;//if weakTime>0,monsters are in the weak state---turn blue
	int deathTime;//if deathTime==0 monsters are in the dead state
	float originX,originY;
	int score;
	hgeSprite *spr;
	hgeSprite *newSpr;
	HGE *hge;
	MonsterAI *ai;
	std::string sprName;
};