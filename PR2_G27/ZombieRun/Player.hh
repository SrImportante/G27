#pragma once
#include <unordered_map>
#include "Map.hh"
#include "Input.inl.hh"

class Player
{
private:
	Map *map;
	int score;
public:
	Player(Map *map2);
	void playerClick(enti::InputKey button);
	int getScore();
	~Player();
};

