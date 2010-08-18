#include "OptionScene.h"
#include "Application.h"
#include "MenuItem.h"
#include "MenuScene.h"
#include "GameScene.h"

OptionScene::OptionScene()
{
	hge = Application::Inst()->Hge();
	manager = Application::Inst()->resMan();
	background = manager->GetSprite("Option");
	snd = manager->GetEffect("Cursor");
	spr=manager->GetSprite("Cursor");
	fnt=manager->GetFont("Menu");
	guiOption=new hgeGUI();
	guiOption->AddCtrl(new hgeGUIMenuItem(1,fnt,snd,340,175,0.2f,"mini"));
	guiOption->AddCtrl(new hgeGUIMenuItem(2,fnt,snd,340,235,0.2f,"normal"));
	guiOption->AddCtrl(new hgeGUIMenuItem(3,fnt,snd,550,390,0.2f,"back"));
	guiOption->SetNavMode(HGEGUI_UPDOWN | HGEGUI_CYCLED);
	guiOption->SetCursor(spr);
	guiOption->SetFocus(1);
	guiOption->Enter();
}

bool OptionScene::FrameFunc()
{
	float dt=hge->Timer_GetDelta();
	int id;
	static int lastid=0;
	
	id=guiOption->Update(dt);
	if(id == -1)
	{
		switch(lastid)
		{
		case 1:
			Application::Inst()->ChangeScene(new GameScene("mini.txt"));
			break;
		case 2:
			Application::Inst()->ChangeScene(new GameScene("mappic.txt"));
			break;
		case 3: 
			Application::Inst()->ChangeScene(new MenuScene());
			break;
		}
	}
	else if(id) 
	{ 
		lastid=id; 
		guiOption->Leave(); 
	}
	return false;
}

bool OptionScene::RenderFunc()
{
	background->Render(0,0);
	guiOption->Render();
	return false;
}

OptionScene::~OptionScene()
{
	delete guiOption;
}
