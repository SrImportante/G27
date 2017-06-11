#pragma once
class Player
{
private:
	Map *map;
public:
	Player(Map *map2);
	void play(enti::InputKey button);
	~Player();
};

