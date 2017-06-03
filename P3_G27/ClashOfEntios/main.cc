#include <stdio.h>
#include <iostream>
#include "Map.hh"
#include "Player.hh"
#include "Input.inl.hh"
#include "Renderer.hh"
#include <conio.h>
#include "Input.inl.hh"

int main()
{
	//std::cout << "" << std::endl;
	Map *myMap = new Map();
	myMap->printMap();

	Player player(myMap, 1);
	//std::cout << "x: " << myMap->getX('A') << "y: " << myMap->getY('A') << std::endl;

	enti::InputKey keyPressed;
	while (!player.allDead())
	{
		if (_kbhit())
		{
			keyPressed = enti::getInputKey();
			player.movePlayer(keyPressed);
			system("cls");
			myMap->printMap();
		}
	}

	_getch();
	return 0;
}