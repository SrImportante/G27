#pragma once
#include <unordered_map>
#include "Map.hh"
#include "Input.inl.hh"

class Player
{
private:
	Map *map;
public:
	Player(Map *map2);
	void play(enti::InputKey button);
	~Player();
};

