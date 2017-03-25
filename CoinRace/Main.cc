#include <iostream>
#include <stdio.h>
#include <ctime>
#include "Map.hh"
#include "CoinManager.hh"
#include "Player.hh"

int main()
{
	srand(static_cast<unsigned>(time(nullptr)));
	Map myMap;
	CoinManager myCoin(myMap);
	Player player(myMap, myCoin);
	int maxCoin{ 50 };
	myMap.printMap();
	return 0;
}