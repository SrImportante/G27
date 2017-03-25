#include <iostream>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include "Map.hh"
#include "CoinManager.hh"
#include "Player.hh"
#include "Input.hh"

int main()
{
	srand(static_cast<unsigned>(time(nullptr)));
	Map myMap;
	CoinManager myCoin(myMap);
	Player player(myMap, myCoin);
	int maxCoin{ 50 };
	Input::Key keyPressed;

	std::clock_t start;
	double duration;
	start = std::clock();
	
	while (maxCoin > player.getScore())
	{
		keyPressed = Input::getKey();
		player.movePlayer(keyPressed);
		system("cls");
		myMap.printMap();
	}

	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	std::cout << "printf: " << duration << '\n';
	
	return 0;
}