#include <iostream>
#include <stdio.h>
#include <ctime>
#include "CoinManager.hh"

CoinManager::CoinManager(Map &map)
{
	srand(static_cast<unsigned>(time(nullptr)));
	coins = (map.getRows()*map.getColumns()*(rand() % 11 + 3))/100; //random entre 3-13
	std::cout << coins;
}