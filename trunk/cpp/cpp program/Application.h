#pragma once

class HGE;
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
private:
	Application();
	void Initialize();
	IScene *current;
	IScene *toBeChanged;
	HGE *hge;
	hgeResourceManager *res;
};