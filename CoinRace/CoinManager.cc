#include <iostream>
#include <stdio.h>
#include <ctime>
#include "CoinManager.hh"

CoinManager::CoinManager(Map &map)
{
	int aux = 0;
	srand(static_cast<unsigned>(time(nullptr)));
	coins = (map.getRows()*map.getColumns()*(rand() % 11 + 3))/100; //random entre 3-13
	std::cout << coins << std::endl;
	do
	{
		int x = rand() % map.getRows();
		int y = rand() % map.getColumns();
		if (map.getCharMatrix(x, y) == '.')
		{
			map.modifyMap(x, y, '$');
			aux++;
		}
	} while (aux < coins);
}

void CoinManager::deleteCoin(int &x, int &y, Map &map)
{
	map.modifyMap(x, y, '.');
}

void CoinManager::generateCoins(Map &map, int numCoins)
{
	int aux = 0;
	do
	{
		int x = rand() % map.getRows();
		int y = rand() % map.getColumns();
		if (map.getCharMatrix(x, y) == '.')
		{
			map.modifyMap(x, y, '$');
			aux++;
		}
	} while (aux < numCoins);
}