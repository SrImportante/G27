#pragma once
#include "Input.hh"

class Player
{
private:
	int x, y, score;
	Map *map; //Relaci� d'associaci�
	CoinManager *coinManager; //Relaci� d'associaci�
public:
	Player(Map *map2, CoinManager *CManager);
	void movePlayer(Input::Key button);
	int getScore();
};