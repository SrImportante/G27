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
	
	std::cout << "//////////////////////////" << std::endl;
	std::cout << "	COIN RACE" << std::endl;
	std::cout << "/////////////////////////" << std::endl;
	std::cout << "\nControls: Use WASD to move the player (@)" << std::endl;
	
	Map myMap;
	CoinManager myCoin(myMap);
	Player player(myMap, myCoin);
	int maxCoin{ rand() % (30 * myMap.getLevel() * 2 - 30 * myMap.getLevel() + 1) + 30 * myMap.getLevel() };
	Input::Key keyPressed;

	std::cout << "\nObjective: You have to pick up " << maxCoin << " coins" << std::endl;

	std::clock_t start;
	double duration;
	start = std::clock();
	
	while (maxCoin > player.getScore())
	{
		if (_kbhit())
		{
			keyPressed = Input::getKey();
			if (keyPressed == Input::Key::ESC) // Sale del bucle si se pulsa ESC y termina la partida
				break;
			player.movePlayer(keyPressed);
			system("cls");
			myMap.printMap();
			std::cout << "\nScore " << player.getScore() << "/" << maxCoin << std::endl;
		}
	}

	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	
	std::cout << "\nYou have picked up " << player.getScore() << " coins in " << duration << " seconds" << std::endl;
	
	_getch();
	_getch();
	return 0;
}