#pragma once

class Monster;
class Map;

class MonsterAI
{
public:
	MonsterAI(Map *map);
	void Action(Monster *monster , float delta);
private:
	int direction;
	int collidTimes;
	int aiState;
	Map *map;
	void move(Monster *monster,float delta);
	void normalAI(int now);
	void smartAI(float monsterX,float monsterY,int now);
	void randDirection(int x,int y);
	bool handleCollide(Monster *monster,float x,float y);
};