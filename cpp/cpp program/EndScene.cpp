#include "EndScene.h"
#include "Application.h"
#include "MenuScene.h"
#include <hgeresource.h>

EndScene::EndScene(bool _win)
{
	span = 180;
	win = _win;
	if(win)
		spr = Application::Inst()->resMan()->GetSprite("Win");
	else
		spr = Application::Inst()->resMan()->GetSprite("Lose");
}

//return to menu after 3 seconds
bool EndScene::FrameFunc()
{
	--span;
	if(span<=0)
		Application::Inst()->ChangeScene(new MenuScene());
	return false;
}

bool EndScene::RenderFunc()
{
	spr->Render(0,0);
	return false;
}