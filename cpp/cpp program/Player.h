#pragma once
#include "IGameObject.h"
#include "MovableObject.h"

class HGE;
class hgeAnimation;
class hgeRect;
class GameScene;

class Player : public MovableObject
{
public:
	Player(GameScene* scene);
	~Player();
	virtual void Update(float delta);
	virtual void Render();
	float BegX() const;
	float BegY() const;
	bool CanEat() const;
	hgeRect* GetBoundingBox();
	void SetLife();
	void SetPos(float x, float y);
	void Revive();
	int GetLife();
	int GetScore();
	void AddScore(int added);
private:
	hgeAnimation *spr;
	int score;
	HGE *hge;
	GameScene *gameScene;
	int life;
	int reviveTime;
	float begX,begY;
	float rotation;
};