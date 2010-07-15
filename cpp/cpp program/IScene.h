#pragma once

class IScene
{
public:
	virtual bool FrameFunc() = 0;
	virtual bool RenderFunc() = 0;
	virtual ~IScene(){};
};