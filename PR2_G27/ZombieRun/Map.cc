#include <iostream>
#include <stdio.h>
#include <ctime>
#include "Map.hh"

Map::Map(int difficulty)
{
	numRows = (30 - 7 * difficulty) + rand() % (31 - 5 * difficulty - (30 - 7 * difficulty)); //crea nombre de files i columnes segons la dificultat escollida
	numColumns = (9 + 5 * difficulty) + rand() % (10 + 7 * difficulty - (9 + 5 * difficulty));

	mapMatrix = new char*[numRows]; //Crea una array dinamica de punters a chars (filas)

	for (int i{ 0 }; i < numRows; i++)
	{
		mapMatrix[i] = new char[numColumns]; //Cada punter esta apuntant a una array dinamica de chars (coumnes)
		for (int j{ 0 }; j < numColumns; j++)
		{
			mapMatrix[i][j] = '.'; //S'omple l'array dinàmica de chars amb cel·les buides
		}
	}
}

void Map::printMap() //funció per imprimir l'array dinàmica
{
	for (int i{ 0 }; i < numRows; i++)
	{
		for (int j{ 0 }; j < numColumns; j++)
		{
			std::cout << mapMatrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	/*for (auto it = zombies.begin(); it != zombies.end(); ++it) //saber el numero de zombies que hi ha per cada lletra
		std::cout << it->first << " hi ha " << it->second << std::endl;*/
}

void Map::createZombie(int num)
{
	for (int i = 0; i < num; i++)
	{
		zombie randomZombie{ 65 + rand() % (91 - 65), 0, rand() % (numColumns + 1) };
		while (getCharMatrix(0, randomZombie.y) != '.') // vigila que no crei zombies en el mateix lloc
		{
			randomZombie.y = rand() % (numColumns + 1);
		}
		++zombies[randomZombie.name]; // si exiteix el zombi incrementa el valor i sino el posa a 0;
		mapMatrix[randomZombie.x][randomZombie.y] = randomZombie.name;
	}
}

int Map::killZombies(char letter)
{
	int numZombies;

	for (int i{ 0 }; i < numRows; i++)
	{
		for (int j{ 0 }; j < numColumns; j++)
		{
			if (getCharMatrix(i, j) == (letter > 91 ? letter - 32 : letter))
			{
				mapMatrix[i][j] = '.';
			}
		}
	}

	numZombies = zombies[letter > 91 ? letter - 32 : letter];
	zombies.erase(letter > 91 ? letter - 32 : letter);
	return numZombies;
}

void Map::moveZombies()
{
	char** auxMapMatrix;
	auxMapMatrix = new char*[numRows];
	for (int i{ 0 }; i < numRows; i++)
	{
		auxMapMatrix[i] = new char[numColumns];
		for (int j{ 0 }; j < numColumns; j++)
		{
			auxMapMatrix[i][j] = mapMatrix[i][j];
		}
	}

	for (int i{ numRows - 1 }; i > 0 ; i--)
	{
		for (int j{ 0 }; j < numColumns; j++)
		{
			mapMatrix[i][j] = auxMapMatrix[i-1][j];
			mapMatrix[i - 1][j] = '.';
		}
	}
}

void Map::modifyMap(int &x, int &y, char element) //canvia el caràcter de la cel·la en que es troba el jugador
{
	mapMatrix[x][y] = element;
}

char Map::getCharMatrix(int x, int y) //funció per retornar el caràcter que es troba en la cel·la
{
	return mapMatrix[x][y];
}

bool Map::zombiesWin()
{
	bool finish = false;
	for (int i = 0; i < numColumns; i++)
	{
		if (getCharMatrix(numRows-1, i) != '.')
			finish = true;
	}
	return finish;
}

Map::~Map()
{
}
