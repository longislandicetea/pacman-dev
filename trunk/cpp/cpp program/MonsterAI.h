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
	void normalAI( Monster *monster,int now,float oldX,float oldY);
	void smartAI(Monster *monster,int now,float oldX,float oldY);
	void randDirection(int x,int y);
	bool handleCollide(Monster *monster,float x,float y);
	bool isAway(float monsterX,float monsterY,float playerX,float playerY,int now);
};