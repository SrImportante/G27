#include <iostream>
#include <stdio.h>
#include "Player.hh"

Player::Player(Map &map2, CoinManager &CManager) :
	map(map2),
	coinManager(CManager),
	score(0)
{
	do {
		x = rand() % map.getRows();
		y = rand() % map.getColumns();
	} while (map.getCharMatrix(x, y) != '.');
	map.modifyMap(x, y, '@');
};

void Player::movePlayer(Input::key button)
{
	switch (button)
	{
	case Input::key::A:
		if (y > 0)
		{
			map.modifyMap(x, y, '.');
			y--;
		}	
		if (map.getCharMatrix(x, y) == '$')
		{
			score++;
			coinManager.pickCoin();
			if (!coinManager.anyCoin())
				coinManager.generateCoins((map.getRows()*map.getColumns()*(rand() % 11 + 3)) / 100);
		}
		map.modifyMap(x, y, '@');
		//eliminar moneda
		break;
	case Input::key::D:
		break;
	case Input::key::S:
		break;
	case Input::key::W:
		break;
	}
}