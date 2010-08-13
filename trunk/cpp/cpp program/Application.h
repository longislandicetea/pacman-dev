#pragma once
#include <hge.h>

class IScene;
class hgeResourceManager;

class Application
{
public:
	static Application* Inst();
	~Application();
	static bool FrameFunc();
	static bool RenderFunc();
	HGE* Hge();
	hgeResourceManager* resMan();
	void Run();
	void ChangeScene(IScene* scene);
	HCHANNEL GetChannel();
private:
	Application();
	void Initialize();
	IScene *current;
	IScene *toBeChanged;
	HGE *hge;
	hgeResourceManager *res;
	HCHANNEL channel;
};