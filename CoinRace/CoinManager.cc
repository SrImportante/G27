#include <iostream>
#include <stdio.h>
#include "Map.hh"
#include "CoinManager.hh"

CoinManager::CoinManager(Map &map2) : //Crea el màxim de monedes segons la dificultat i les col·loca de manera aleatòria en el mapa
	map(map2),
	coins((map2.getRows()*map2.getColumns()*(rand() % 11 + 3))/100) //No puedo poner map directamente, al debuggar se salta esta linea.
{
	int aux{ 0 }, x, y;
	
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

void CoinManager::generateCoins(int numCoins) //torna a col·locar monedes en el mapa
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

bool CoinManager::anyCoin() //comprova si queden monedes
{
	return coins > 0;
}
void CoinManager::pickCoin() //resta una moneda
{
	coins--;
}