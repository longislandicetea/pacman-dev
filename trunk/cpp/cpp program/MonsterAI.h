#pragma once

class Monster;
class Map;

class MonsterAI
{
public:
	MonsterAI(Map *map);
	void Action(Monster *rhs , float delta);
private:
	int direction[2];
	void SetDirection(Monster *rhs);
	Map *map;
};