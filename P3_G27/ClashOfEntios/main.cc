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
	Map *myMap = new Map();
	myMap->printMap();

	Player player1(myMap, 1);
	Player player2(myMap, 2);

	bool turn1 = true;

	enti::InputKey keyPressed;
	while (!player1.allDead() || !player2.allDead()) 
	{
		if (_kbhit())
		{
			keyPressed = enti::getInputKey();
			switch (keyPressed)
			{
			case enti::InputKey::NONE:
				break;
			case enti::InputKey::w: case enti::InputKey::W: case enti::InputKey::a: case enti::InputKey::A: case enti::InputKey::s: case enti::InputKey::S: 
			case enti::InputKey::d: case enti::InputKey::D: case enti::InputKey::z: case enti::InputKey::Z: 
				if (turn1 && player1.getActions() > 0)
				{
					player1.movePlayer(keyPressed);
					system("cls");
					myMap->printMap();
					std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nActions: " << player1.getActions() << std::endl;
				}
				else if (!turn1 && player2.getActions() > 0)
				{
					player2.movePlayer(keyPressed);
					system("cls");
					myMap->printMap();
					std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nActions: " << player2.getActions() << std::endl;
				}
				else
				{
					system("cls");
					myMap->printMap();
					std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nNo queden accions" << std::endl;
					std::cout << "ENTER per passar el torn" << std::endl;
				}
				break;
			case enti::InputKey::ENTER:
				if (turn1 && player1.getActions() > 0)
				{
					player1.switchEntio();
					system("cls");
					myMap->printMap();
					std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nActions: " << player1.getActions() << std::endl;
				}
				else if (!turn1 && player2.getActions() > 0)
				{
					player2.switchEntio();
					system("cls");
					myMap->printMap();
					std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nActions: " << player2.getActions() << std::endl;
				}
				else
				{
					if (turn1)
					{
						player1.setActions(10);
						player1.switchEntio();
					}
					else
					{
						player2.setActions(10);
						player2.switchEntio();
					}
					turn1 = !turn1;	
				}
				break;
			case enti::InputKey::SPACEBAR:

				if (turn1 && player1.getActions() > 0)
				{
					system("cls");
					myMap->printMap();
					std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nEnter the weapon you want to choose: " << std::endl;
					enti::cout << enti::Color::YELLOW << "1 - SWORD \n2 - BOW" << enti::endl << enti::cend;
					if (keyPressed == enti::InputKey::NUM1)
					{
						system("cls");
						myMap->printMap();
						std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nEnter the direction to attack: " << std::endl;
						enti::cout << enti::Color::YELLOW << "1 - UP \n2 - LEFT \n3 - DOWN \n4 - RIGHT" << enti::endl << enti::cend;
						player1.playerAttackSword(keyPressed);
					}
					else if (keyPressed == enti::InputKey::NUM2)
					{

					}
				}
				else if (!turn1 && player2.getActions() > 0)
				{
					system("cls");
					myMap->printMap();
					std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nEnter the weapon you want to choose: " << std::endl;
					enti::cout << enti::Color::YELLOW << "1 - SWORD \n2 - BOW" << enti::endl << enti::cend;
					if (keyPressed == enti::InputKey::NUM1)
					{
						system("cls");
						myMap->printMap();
						std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nEnter the direction to attack: " << std::endl;
						enti::cout << enti::Color::YELLOW << "1 - UP \n2 - LEFT \n3 - DOWN \n4 - RIGHT" << enti::endl << enti::cend;
						player2.playerAttackSword(keyPressed);
					}
					else if (keyPressed == enti::InputKey::NUM2)
					{

					}
				}
				else
				{
					system("cls");
					myMap->printMap();
					std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nNo queden accions" << std::endl;
					std::cout << "ENTER per passar el torn" << std::endl;
				}
				break;
			case enti::InputKey::ESC:
				system("cls");
				myMap->printMap();
				std::cout << "ESC: " << std::endl;
				break;
			default:
				break;
			}
		}
	}
	
	_getch();
	return 0;
}