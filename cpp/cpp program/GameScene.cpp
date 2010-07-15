#include "GameScene.h"
#include "Application.h"
#include "Map.h"
#include "Player.h"
#include <vector>

GameScene::GameScene()
{
	gameMap=new Map(this);
	gameMap->SetMap("mapinfo.txt");
	player=new Player(this);
}

bool GameScene::FrameFunc()
{
	float dt = Application::Inst()->Hge()->Timer_GetDelta();
	player->Update(dt);
	gameMap->Update(dt);
	return false;
}

bool GameScene::RenderFunc()
{
	player->Render();
	gameMap->Render();
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