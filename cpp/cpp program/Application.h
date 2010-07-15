#pragma once

class HGE;
class IScene;
class hgeResourceManager;

class Application
{
public:
	static Application* Inst();
	void Run();
	HGE* Hge();
	hgeResourceManager* resMan();
	static bool FrameFunc();
	static bool RenderFunc();
	~Application();
private:
	Application();
	void Initialize();
	IScene *current;
	HGE *hge;
	hgeResourceManager *res;
};