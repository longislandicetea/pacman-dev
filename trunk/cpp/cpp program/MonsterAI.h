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
	Map *map;
	void move(Monster *monster,float delta);
	void normalAI(int now);
	void smartAI(float monsterX,float monsterY,int now);
	void randDirection(int x,int y);
	void handleCollide(Monster *monster,float x,float y);
};