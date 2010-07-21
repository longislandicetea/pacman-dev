#include "EndScene.h"
#include "Application.h"
#include "MenuScene.h"
#include <hgeresource.h>

EndScene::EndScene(bool _win)
{
	fnt = Application::Inst()->resMan()->GetFont("End");
	span = 240;
	win = _win;
	if(win)
		spr = Application::Inst()->resMan()->GetSprite("Win");
	else
		spr = Application::Inst()->resMan()->GetSprite("Lose");
}

bool EndScene::FrameFunc()
{
	--span;
	if(span<=0)
		Application::Inst()->ChangeScene(new MenuScene());
	return false;
}

bool EndScene::RenderFunc()
{
	spr->Render(250,300);
	
	if(win)
		fnt->printf(440,260,HGETEXT_CENTER,"Congratulations!\n\nYou win!");
	else
		fnt->printf(460,300,HGETEXT_CENTER,"Game Over");
	
	return false;
}