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

	Map *myMap = new Map();
	clock_t timeCounter = 0; // clock tick timer

	while (true)
	{
		if (clock() / (CLOCKS_PER_SEC / 1000) > timeCounter + 1000)
		{
			system("cls");
			myMap->printMap();
			myMap->moveZombies();
			myMap->createZombie(4);
			timeCounter = clock() / (CLOCKS_PER_SEC / 1000);
			std::cout << timeCounter << std::endl;
		}
	}

	_getch();
	_getch();
	return 0;
}
