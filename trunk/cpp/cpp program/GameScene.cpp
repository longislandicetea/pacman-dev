#include "GameScene.h"
#include "Application.h"
#include "Map.h"
#include <hgeresource.h>
#include <hgefont.h>
#include "Player.h"
#include <vector>

GameScene::GameScene()
{
	paused = false;
	gameMap = new Map(this);
	gameMap->SetMap("mappic.txt");
	player = new Player(this);
	fnt = Application::Inst()->resMan()->GetFont("ScoreAndLife");
	pauseFnt = Application::Inst()->resMan()->GetFont("ScoreAndLife");
}

bool GameScene::FrameFunc()
{
	if (Application::Inst()->Hge()->Input_KeyUp(HGEK_SPACE))
		paused = !paused;
	if (paused)
		return false;
	float dt = Application::Inst()->Hge()->Timer_GetDelta();
	player->Update(dt);
	gameMap->Update(dt);
	return false;
}

bool GameScene::RenderFunc()
{
	player->Render();
	gameMap->Render();
	fnt->printf(30,30,HGETEXT_LEFT,"Score:%d\nLife:%d",GetPlayer()->GetScore(),GetPlayer()->GetLife());
	if(paused)
		pauseFnt->printf(200,200,HGETEXT_LEFT,"pause");
	return false;
}

GameScene::~GameScene()
{
	delete player;
	delete gameMap;
}

Map* GameScene::GetMap()
{
	return gameMap;
}

Player* GameScene::GetPlayer()
{
	return player;
}