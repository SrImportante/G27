#pragma once
#include "Input.hh"

class Player
{
private:
	int x, y, score;
	Map *map; //Relació d'associació
	CoinManager *coinManager; //Relació d'associació
public:
	Player(Map *map2, CoinManager *CManager);
	void movePlayer(Input::Key button);
	int getScore();
};