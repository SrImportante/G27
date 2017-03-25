#include <iostream>
#include <stdio.h>
#include "CoinManager.hh"

CoinManager::CoinManager(Map &map2) :
	map(map2),
	coins((map2.getRows()*map2.getColumns()*(rand() % 11 + 3))/100) //No puedo poner map directamente, al debuggar se salta esta linea.
{
	int aux{ 0 }, x, y;
	std::cout << coins << std::endl;
	do {
		x = rand() % map.getRows();
		y = rand() % map.getColumns();
		if (map.getCharMatrix(x, y) == '.')
		{
			map.modifyMap(x, y, '$');
			aux++;
		}
	} while (aux < coins);
};

void CoinManager::generateCoins(int numCoins)
{
	int aux{ 0 }, x, y;
	coins = numCoins;
	do
	{
		x =rand() % map.getRows();
		y = rand() % map.getColumns();
		if (map.getCharMatrix(x, y) == '.')
		{
			map.modifyMap(x, y, '$');
			aux++;
		}
	} while (aux < coins);
}

bool CoinManager::anyCoin()
{
	return coins > 0;
}
void CoinManager::pickCoin()
{
	coins--;
}