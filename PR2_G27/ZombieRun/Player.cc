#include <unordered_map>
#include "Player.hh"
#include "Map.hh"
#include "Input.inl.hh"


Player::Player(Map *map2) :
	map(map2),
	score(0)
{
};

void Player::playerClick(enti::InputKey button)
{
	score += map->killZombies(static_cast<char>(button));
}

int Player::getScore()
{
	return score;
}

Player::~Player()
{
}
