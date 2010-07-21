#include "MenuScene.h"
#include "Application.h"
#include "MenuItem.h"
#include "GameScene.h"

MenuScene::MenuScene()
{
	hge=Application::Inst()->Hge();
	manager=Application::Inst()->resMan();
	background = manager->GetSprite("Background");
	snd=manager->GetEffect("CursorSound");
	spr=manager->GetSprite("Cursor");
	fnt=manager->GetFont("Menu");
	guiMenu=new hgeGUI();
	guiMenu->AddCtrl(new hgeGUIMenuItem(1,fnt,snd,400,400,0.0f,"Start"));
	guiMenu->AddCtrl(new hgeGUIMenuItem(3,fnt,snd,400,450,0.2f,"Instructions"));
	guiMenu->AddCtrl(new hgeGUIMenuItem(5,fnt,snd,400,500,0.4f,"Exit"));

	guiMenu->SetNavMode(HGEGUI_UPDOWN | HGEGUI_CYCLED);
	guiMenu->SetCursor(spr);
	guiMenu->SetFocus(1);
	guiMenu->Enter();
}

bool MenuScene::FrameFunc()
{
	float dt=hge->Timer_GetDelta();
	int id;
	static int lastid=0;
	if(hge->Input_GetKeyState(HGEK_ESCAPE)) 
	{ 
		lastid=5; 
		guiMenu->Leave(); 
	}
	id=guiMenu->Update(dt);
	if(id == -1)
	{
		switch(lastid)
		{
		case 1:
			Application::Inst()->ChangeScene(new GameScene());
			break;
		case 2:
		case 3:
		case 4:
			guiMenu->SetFocus(1);
			guiMenu->Enter();
			break;
		case 5: return true;
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
