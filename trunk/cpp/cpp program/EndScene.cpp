#include "EndScene.h"
#include "Application.h"
#include "MenuScene.h"
#include <hgeresource.h>

EndScene::EndScene(bool _win)
{
	span = 240;
	win = _win;
	Application::Inst()->Hge()->Channel_Pause(Application::Inst()->GetChannel());
	if(win)
	{
		spr = Application::Inst()->resMan()->GetSprite("Win");
		backSnd = Application::Inst()->Hge()->Music_Play(Application::Inst()->resMan()->GetStream("Win"),false);
	}
	else
	{
		spr = Application::Inst()->resMan()->GetSprite("Lose");
		backSnd = Application::Inst()->Hge()->Music_Play(Application::Inst()->resMan()->GetStream("Lose"),false);
	}
}

//return to menu after 4 seconds
bool EndScene::FrameFunc()
{
	--span;
	Application::Inst()->Hge()->Channel_Resume(backSnd);
	if(span<=0)
	{
		Application::Inst()->ChangeScene(new MenuScene());
		Application::Inst()->Hge()->Channel_Pause(backSnd);
	}
	return false;
}

bool EndScene::RenderFunc()
{
	spr->Render(0,0);
	return false;
}