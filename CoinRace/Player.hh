#pragma once
#include "Map.hh"
#include "CoinManager.hh"
#include "Input.hh"


class Player
{
private:
	int x, y, score;
	Map map;
	CoinManager coinManager;
public:
	Player(Map &map2, CoinManager &CManager);
	void movePlayer(Input::key button);
	int getScore();
};