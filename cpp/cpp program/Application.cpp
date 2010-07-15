#include "Application.h"
#include "IScene.h"
#include <hge.h>
#include <cassert>
#include "GameScene.h"
#include <hgeresource.h>

Application::Application()
{
	Initialize();
	res = new hgeResourceManager("1.txt");
	current = new GameScene();
}


void Application::Run()
{
	hge->System_Start();
}

bool Application::FrameFunc()
{
	return Inst()->current->FrameFunc();
}

bool Application::RenderFunc()
{
	HGE *hge = Inst()->hge;
	hge->Gfx_BeginScene();
	hge->Gfx_Clear(0);
	bool ret = Inst()->current->RenderFunc();
	hge->Gfx_EndScene();
	return ret;
}

Application* Application::Inst()
{
	static Application _app;
	return &_app;
}

HGE* Application::Hge()
{
	return hge;
}

Application::~Application()
{
	delete current;
	delete res;
	hge->System_Shutdown();
	hge->Release();
}

void Application::Initialize()
{
	hge = hgeCreate(HGE_VERSION);
	hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);
	hge->System_SetState(HGE_RENDERFUNC,RenderFunc);
	hge->System_SetState(HGE_LOGFILE,"log.txt");
	hge->System_SetState(HGE_TITLE, "Pacman");
	hge->System_SetState(HGE_WINDOWED, true);
	hge->System_SetState(HGE_USESOUND, false);
	assert(hge->System_Initiate());
}

hgeResourceManager* Application::resMan()
{
	return res;
}
