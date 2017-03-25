#include <iostream>
#include <stdio.h>
#include "Map.hh"
#include "CoinManager.hh"
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

void Player::movePlayer(Input::Key keyPressed)
{
	switch (keyPressed)
	{
	case Input::Key::A:
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
	case Input::Key::D:
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
	case Input::Key::S:
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
	case Input::Key::W:
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