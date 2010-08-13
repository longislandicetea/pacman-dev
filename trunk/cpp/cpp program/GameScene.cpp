#include "GameScene.h"
#include "Application.h"
#include "Map.h"
#include "MenuScene.h"
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
	eatSnd = Application::Inst()->resMan()->GetEffect("Eat");
}

bool GameScene::FrameFunc()
{
	if (Application::Inst()->Hge()->Input_KeyUp(HGEK_SPACE))
		paused = !paused;
	if (paused)
	{
		Application::Inst()->Hge()->Channel_Pause(Application::Inst()->GetChannel());
		return false;
	}
	else
		Application::Inst()->Hge()->Channel_Resume(Application::Inst()->GetChannel());
	if(Application::Inst()->Hge()->Input_KeyUp(HGEK_ESCAPE))
		Application::Inst()->ChangeScene(new MenuScene);
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
		pauseFnt->printf(340,240,HGETEXT_CENTER,"pause");
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

HEFFECT* GameScene::GetEatSnd()
{
	return &eatSnd;
}