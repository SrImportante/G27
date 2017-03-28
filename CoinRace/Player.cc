#include <iostream>
#include <stdio.h>
#include "Map.hh"
#include "CoinManager.hh"
#include "Player.hh"

Player::Player(Map *map2, CoinManager *CManager) : // crea al jugador i el col�loca en una cel�la que no estigui ocupada per una moneda
	map(map2),
	coinManager(CManager),
	score(0)
{
	do {
		x = rand() % map->getRows();
		y = rand() % map->getColumns();
	} while (map->getCharMatrix(x, y) != '.');
	map->modifyMap(x, y, '@');
};

void Player::movePlayer(Input::Key keyPressed) // mou el jugador segons la tecla premuda 
{
	switch (keyPressed)
	{
	case Input::Key::A:
		if (y > 0) //canvia la posici� anterior per una cel�la buida i mou la posici� del jugador 
		{
			map->modifyMap(x, y, '.');
			y--;
		}
		if (map->getCharMatrix(x, y) == '$') //si en la cel�la es troba una moneda augmenta la puntuaci� i crida a la funci� pickCoin()
		{
			score++;
			coinManager->pickCoin();
		}
		map->modifyMap(x, y, '@'); //coloca el car�cter del jugador en la nova posici�
		if (!coinManager->anyCoin()) //si no hi han m�s monedes en el mapa crida la funci� generateCoins() i en crea de noves
			coinManager->generateCoins((map->getRows()*map->getColumns()*(rand() % 11 + 3)) / 100);
		break;
	case Input::Key::D:
		if (y < map->getColumns() - 1)
		{
			map->modifyMap(x, y, '.');
			y++;
		}
		if (map->getCharMatrix(x, y) == '$')
		{
			score++;
			coinManager->pickCoin();
		}
		map->modifyMap(x, y, '@');
		if (!coinManager->anyCoin())
			coinManager->generateCoins((map->getRows()*map->getColumns()*(rand() % 11 + 3)) / 100);
		break;
	case Input::Key::S:
		if (x < map->getRows() - 1)
		{
			map->modifyMap(x, y, '.');
			x++;
		}
		if (map->getCharMatrix(x, y) == '$')
		{
			score++;
			coinManager->pickCoin();
		}
		map->modifyMap(x, y, '@');
		if (!coinManager->anyCoin())
			coinManager->generateCoins((map->getRows()*map->getColumns()*(rand() % 11 + 3)) / 100);
		break;
	case Input::Key::W:
		if (x > 0)
		{
			map->modifyMap(x, y, '.');
			x--;
		}
		if (map->getCharMatrix(x, y) == '$')
		{
			score++;
			coinManager->pickCoin();
		}
		map->modifyMap(x, y, '@');
		if (!coinManager->anyCoin())
			coinManager->generateCoins((map->getRows()*map->getColumns()*(rand() % 11 + 3)) / 100);
		break;
	}
}

int Player::getScore() //retorna la puntuaci� actual
{
	return score;
}