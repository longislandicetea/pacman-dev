#include "MenuScene.h"
#include "Application.h"
#include "MenuItem.h"
#include "GameScene.h"
#include "HelpScene.h"
#include "OptionScene.h"

MenuScene::MenuScene()
{
	hge = Application::Inst()->Hge();
	manager = Application::Inst()->resMan();
	hge->Channel_SetPos(Application::Inst()->GetChannel(),0.0f);
	background = manager->GetSprite("Background");
	snd = manager->GetEffect("Cursor");
	spr=manager->GetSprite("Cursor");
	fnt=manager->GetFont("Menu");
	guiMenu=new hgeGUI();
	guiMenu->AddCtrl(new hgeGUIMenuItem(1,fnt,snd,320,300,0.0f,"Start"));
	guiMenu->AddCtrl(new hgeGUIMenuItem(2,fnt,snd,320,350,0.2f,"Help"));
	guiMenu->AddCtrl(new hgeGUIMenuItem(3,fnt,snd,320,400,0.4f,"Exit"));
	guiMenu->SetNavMode(HGEGUI_UPDOWN | HGEGUI_CYCLED);
	guiMenu->SetCursor(spr);
	guiMenu->SetFocus(1);
	guiMenu->Enter();
}

bool MenuScene::FrameFunc()
{
	float dt=hge->Timer_GetDelta();
	hge->Channel_Resume(Application::Inst()->GetChannel());
	int id;
	static int lastid=0;
	if(hge->Input_GetKeyState(HGEK_ESCAPE)) 
	{ 
		lastid=3; 
		guiMenu->Leave(); 
	}
	id=guiMenu->Update(dt);
	if(id == -1)
	{
		switch(lastid)
		{
		case 1:
			Application::Inst()->ChangeScene(new OptionScene());
			break;
		case 2:
			Application::Inst()->ChangeScene(new HelpScene());
			break;
		case 3: return true;
		}
	}
	else if(id) 
	{ 
		lastid=id; 
		guiMenu->Leave(); 
	}
	return false;
}

bool MenuScene::RenderFunc()
{
	background->Render(0,0);
	guiMenu->Render();
	return false;
}

MenuScene::~MenuScene()
{
	delete guiMenu;
}
