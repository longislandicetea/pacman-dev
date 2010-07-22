#include "HelpScene.h"
#include "Application.h"
#include "MenuItem.h"
#include "MenuScene.h"


HelpScene::HelpScene()
{
	hge=Application::Inst()->Hge();
	manager=Application::Inst()->resMan();
	background = manager->GetSprite("Help");
	snd=manager->GetEffect("CursorSound");
	spr=manager->GetSprite("Cursor");
	fnt=manager->GetFont("Menu");
	guiHelp=new hgeGUI();
	guiHelp->AddCtrl(new hgeGUIMenuItem(1,fnt,snd,550,400,0.0f,"Back"));
	guiHelp->SetNavMode(HGEGUI_UPDOWN | HGEGUI_CYCLED);
	guiHelp->SetCursor(spr);
	guiHelp->SetFocus(1);
	guiHelp->Enter();
}

bool HelpScene::FrameFunc()
{
	float dt=hge->Timer_GetDelta();
	int id;
	static int lastid=0;
	id=guiHelp->Update(dt);
	if(id == -1)
	{
		switch(lastid)
		{
		case 1:
			Application::Inst()->ChangeScene(new MenuScene());
			break;
		}
	}
	else if(id) 
	{ 
		lastid=id; 
		guiHelp->Leave(); 
	}
	return false;
}

bool HelpScene::RenderFunc()
{
	background->Render(0,0);
	guiHelp->Render();
	return false;
}

HelpScene::~HelpScene()
{
	delete guiHelp;
}