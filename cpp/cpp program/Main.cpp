#include"Application.h"
#include<hge.h>

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::Inst()->Run();
	return 0;
}