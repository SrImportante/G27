#include <iostream>
#include <ctime>
#include <stdio.h>      
#include <stdlib.h> 
#include <time.h>  
#include "Input.inl.hh"
#include "Player.hh" 
#include "Map.hh"



int main()
{
	srand(time(NULL));

	int difficulty;
	std::cout << "\nChoose a difficulty:\n\n1 - EASY *\n2 - MEDIUM **\n3 - HARD ***\n" << std::endl;
	std::cin >> difficulty; //el jugador introdueix la dificultat
	
	Map *myMap = new Map(difficulty);
	Player player(myMap);

	clock_t timeCounter = 0; // clock tick timer
	enti::InputKey keyPressed;
	int level = 1;

	while (!myMap->zombiesWin())
	{
		if (_kbhit())
		{
			keyPressed = enti::getInputKey();
			player.playerClick(keyPressed);
		}
		if (clock() / (CLOCKS_PER_SEC / 1000) > timeCounter + 1000)
		{
			myMap->moveZombies();
			myMap->createZombie(1 * difficulty + (level - 1));
			system("cls");
			myMap->printMap();
			std::cout << "Puntuacio: " << player.getScore() << std::endl;
			if (player.getScore() >= level * 10)
				level++;
			timeCounter = clock() / (CLOCKS_PER_SEC / 1000);
		}
	}
	system("cls");
	myMap->printMap();
	std::cout << "############## Puntuacio Final: " << player.getScore() << " ##############" << std::endl;

	_getch();
	_getch();
	return 0;
}
