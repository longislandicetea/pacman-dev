#pragma once

class IGameObject
{
public:
	virtual void Update(float delta) =0;
	virtual void Render() =0;
	int GetScore();
	virtual ~IGameObject(){};
	float PosX();
	float PosY();
	void SetPos(float x , float y);
protected:
	int score;
	float posX,posY;
};