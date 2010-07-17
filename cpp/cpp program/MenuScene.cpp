#include "MenuScene.h"
#include "Application.h"
#include "MenuItem.h"
#include "GameScene.h"

MenuScene::MenuScene()
{
	hge=Application::Inst()->Hge();
	manager=Application::Inst()->resMan();
	quad.tex=manager->GetTexture("Background");
	snd=manager->GetEffect("CursorSound");
	quad.blend=BLEND_ALPHABLEND | BLEND_COLORMUL | BLEND_NOZWRITE;
	spr=manager->GetSprite("Cursor");
	fnt=manager->GetFont("MenuFont");
	
	guiMenu=new hgeGUI();
	guiMenu->AddCtrl(new hgeGUIMenuItem(1,fnt,snd,400,200,0.0f,"Play"));
	guiMenu->AddCtrl(new hgeGUIMenuItem(2,fnt,snd,400,240,0.1f,"Options"));
	guiMenu->AddCtrl(new hgeGUIMenuItem(3,fnt,snd,400,280,0.2f,"Instructions"));
	guiMenu->AddCtrl(new hgeGUIMenuItem(4,fnt,snd,400,320,0.3f,"Credits"));
	guiMenu->AddCtrl(new hgeGUIMenuItem(5,fnt,snd,400,360,0.4f,"Exit"));

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
	hge->Gfx_BeginScene();
	hge->Gfx_RenderQuad(&quad);
	guiMenu->Render();
	hge->Gfx_EndScene();
	return false;
}

MenuScene::~MenuScene()
{
	delete guiMenu;
}
