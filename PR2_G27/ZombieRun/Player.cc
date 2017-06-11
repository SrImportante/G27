#include <unordered_map>
#include "Player.hh"
#include "Map.hh"
#include "Input.inl.hh"


Player::Player(Map *map2)
{
	map = map2;
}

void Player::play(enti::InputKey button)
{
	char letter = static_cast<char>(button);
	map->killZombie(letter);
}

Player::~Player()
{
}
