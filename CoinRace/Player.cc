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
		}
		map.modifyMap(x, y, '@');
		if (!coinManager.anyCoin())
			coinManager.generateCoins((map.getRows()*map.getColumns()*(rand() % 11 + 3)) / 100);
		break;
	case Input::key::D:
		if (y < map.getColumns() - 1)
		{
			map.modifyMap(x, y, '.');
			y++;
		}
		if (map.getCharMatrix(x, y) == '$')
		{
			score++;
			coinManager.pickCoin();
		}
		map.modifyMap(x, y, '@');
		if (!coinManager.anyCoin())
			coinManager.generateCoins((map.getRows()*map.getColumns()*(rand() % 11 + 3)) / 100);
		break;
	case Input::key::S:
		if (x < map.getRows() - 1)
		{
			map.modifyMap(x, y, '.');
			x++;
		}
		if (map.getCharMatrix(x, y) == '$')
		{
			score++;
			coinManager.pickCoin();
		}
		map.modifyMap(x, y, '@');
		if (!coinManager.anyCoin())
			coinManager.generateCoins((map.getRows()*map.getColumns()*(rand() % 11 + 3)) / 100);
		break;
	case Input::key::W:
		if (x > 0)
		{
			map.modifyMap(x, y, '.');
			x--;
		}
		if (map.getCharMatrix(x, y) == '$')
		{
			score++;
			coinManager.pickCoin();
		}
		map.modifyMap(x, y, '@');
		if (!coinManager.anyCoin())
			coinManager.generateCoins((map.getRows()*map.getColumns()*(rand() % 11 + 3)) / 100);
		break;
	}
}

int Player::getScore()
{
	return score;
}