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
	while (!player1.allDead() && !player2.allDead()) 
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
					std::cout << "Torn de ' " << player1.getEntio() << " '"<< std::endl;
				}
				else if (!turn1 && player2.getActions() > 0)
				{
					player2.switchEntio();
					system("cls");
					myMap->printMap();
					std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nActions: " << player2.getActions() << std::endl;
					std::cout << "Torn de ' " << player2.getEntio() << " '" << std::endl;
				}
				else
				{
					if (turn1)
					{
						player1.setActions(11);
						player1.switchEntio();
						system("cls");
						myMap->printMap();
						std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nTorn de ' " << player2.getEntio() << " '" << std::endl;
					}
					else
					{
						player2.setActions(11);
						player2.switchEntio();
						system("cls");
						myMap->printMap();
						std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nTorn de ' " << player1.getEntio() << " '" << std::endl;
					}
					turn1 = !turn1;	
				}
				break;
			case enti::InputKey::SPACEBAR:
				system("cls");
				myMap->printMap();
				std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nEnter the weapon you want to choose: " << std::endl;
				std::cout << /*enti::Color::YELLOW <<*/ "1 - SWORD \n2 - BOW" << std::endl; // << enti::cend;
				if (turn1 && player1.getActions() > 0) // TORN JUGADOR 1
				{
					do // Espera a que es premi una tecla i sigui correcta
					{
						while (!_kbhit())
						{
						}
						keyPressed = enti::getInputKey();
					} while (keyPressed != enti::InputKey::NUM1 && keyPressed != enti::InputKey::NUM2);
					if (keyPressed == enti::InputKey::NUM1)
					{
						system("cls");
						myMap->printMap();
						std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nEnter the direction to attack: " << std::endl;
						std::cout << /*enti::Color::YELLOW <<*/ "1 - UP \n2 - LEFT \n3 - DOWN \n4 - RIGHT" << std::endl; //<< enti::cend;
						do// Espera a que es premi una tecla i sigui correcta
						{
							while (!_kbhit()) 
							{
							}
							keyPressed = enti::getInputKey();
						}while (keyPressed != enti::InputKey::NUM1 && keyPressed != enti::InputKey::NUM2 && keyPressed != enti::InputKey::NUM3 && keyPressed != enti::InputKey::NUM4);
						player1.playerAttackSword(keyPressed, turn1, player2);
						system("cls");
						myMap->printMap();
						std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nActions: " << player1.getActions() << std::endl;
					}else if (keyPressed == enti::InputKey::NUM2)
					{
						system("cls");
						myMap->printMap();
						std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nEnter the direction to attack: " << std::endl;
						std::cout << /*enti::Color::YELLOW <<*/ "1 - UP \n2 - LEFT \n3 - DOWN \n4 - RIGHT" << std::endl; //<< enti::cend;
						do// Espera a que es premi una tecla i sigui correcta
						{
							while (!_kbhit())
							{
							}
							keyPressed = enti::getInputKey();
						} while (keyPressed != enti::InputKey::NUM1 && keyPressed != enti::InputKey::NUM2 && keyPressed != enti::InputKey::NUM3 && keyPressed != enti::InputKey::NUM4);
						player1.playerAttackBow(keyPressed, turn1, player2);
						system("cls");
						myMap->printMap();
						std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nActions: " << player1.getActions() << std::endl;
					}
				}
				else if (!turn1 && player2.getActions() > 0) // TORN JUGADOR 2
				{
					do // Espera a que es premi una tecla i sigui correcta
					{
						while (!_kbhit())
						{
						}
						keyPressed = enti::getInputKey();
					} while (keyPressed != enti::InputKey::NUM1 && keyPressed != enti::InputKey::NUM2);
					if (keyPressed == enti::InputKey::NUM1)
					{
						system("cls");
						myMap->printMap();
						std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nEnter the direction to attack: " << std::endl;
						std::cout << /*enti::Color::YELLOW <<*/ "1 - UP \n2 - LEFT \n3 - DOWN \n4 - RIGHT" << std::endl; // << enti::cend;
						do// Espera a que es premi una tecla i sigui correcta
						{
							while (!_kbhit())
							{
							}
							keyPressed = enti::getInputKey();
						} while (keyPressed != enti::InputKey::NUM1 && keyPressed != enti::InputKey::NUM2 && keyPressed != enti::InputKey::NUM3 && keyPressed != enti::InputKey::NUM4);
						player2.playerAttackSword(keyPressed, turn1, player1);
						system("cls");
						myMap->printMap();
						std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nActions: " << player1.getActions() << std::endl;
					}
					else if (keyPressed == enti::InputKey::NUM2)
					{
						system("cls");
						myMap->printMap();
						std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nEnter the direction to attack: " << std::endl;
						std::cout << /*enti::Color::YELLOW <<*/ "1 - UP \n2 - LEFT \n3 - DOWN \n4 - RIGHT" << std::endl; //<< enti::cend;
						do// Espera a que es premi una tecla i sigui correcta
						{
							while (!_kbhit())
							{
							}
							keyPressed = enti::getInputKey();
						} while (keyPressed != enti::InputKey::NUM1 && keyPressed != enti::InputKey::NUM2 && keyPressed != enti::InputKey::NUM3 && keyPressed != enti::InputKey::NUM4);
						player2.playerAttackBow(keyPressed, turn1, player1);
						system("cls");
						myMap->printMap();
						std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nActions: " << player1.getActions() << std::endl;
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