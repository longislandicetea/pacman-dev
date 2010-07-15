#pragma once
#include <hge.h>
#include "IGameObject.h"
#include "MovableObject.h"
class hgeSprite;
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
	float State();
	void SetState(float val) { state = val; }
private:
	hgeSprite *spr;
	HGE *hge;
	GameScene *gameScene;
	float state;
};