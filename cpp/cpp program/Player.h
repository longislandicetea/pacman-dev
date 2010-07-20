#pragma once
#include <hge.h>
#include "IGameObject.h"
#include "MovableObject.h"
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
	hgeRect* GetBoundingBox();
	float BegX();
	float BegY();
	int GetLife();
	void SetLife();
	int GetScore();
	void AddScore(int added);
	void SetPos(float x, float y);
private:
	hgeAnimation* spr;
	int score;
	HGE *hge;
	GameScene *gameScene;
	int life;
	float begX,begY;
	float rotation;
};