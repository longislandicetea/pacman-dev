#include "Application.h"
#include "IScene.h"
#include <hge.h>
#include <cmath>
#include <cassert>
#include "MenuScene.h"
#include <hgeresource.h>
#include "resource.h"

Application::Application()
{
	Initialize();
	srand(12345);
	res = new hgeResourceManager("1.txt");
	current = new MenuScene();
	channel = hge->Music_Play(res->GetStream("ThemeMusic"),true,80);
	toBeChanged = NULL;
}

void Application::Run()
{
	hge->System_Start();
}

bool Application::FrameFunc()
{
	if (Inst()->toBeChanged!=NULL) 
	{
		delete Inst()->current;
		Inst()->current = Inst()->toBeChanged;
		Inst()->toBeChanged = NULL;
	}
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

//singleton
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
	delete toBeChanged;
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
	hge->System_SetState(HGE_USESOUND, true);
	hge->System_SetState(HGE_ICON,MAKEINTRESOURCE(IDI_ICON1));
	hge->System_SetState(HGE_SHOWSPLASH,false);
	hge->System_SetState(HGE_SCREENWIDTH,680);
	hge->System_SetState(HGE_SCREENHEIGHT,480);
	hge->System_SetState(HGE_FPS,60);
	hge->System_Initiate();
}

hgeResourceManager* Application::resMan()
{
	return res;
}

void Application::ChangeScene( IScene* scene )
{
	toBeChanged = scene;
}

HCHANNEL Application::GetChannel()
{
	return channel;
}
