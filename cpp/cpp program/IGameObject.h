#pragma once

class IGameObject
{
public:
	virtual void Update(float delta) =0;
	virtual void Render() =0;
	virtual ~IGameObject(){};
};