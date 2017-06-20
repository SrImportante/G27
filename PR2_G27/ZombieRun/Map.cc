#include <iostream>
#include <stdio.h>
#include <map>
#include <ctime>
#include "Map.hh"

std::istream& operator >> (std::istream &is, Map::Level &lvl)
{
	int intVal;
	is >> intVal;
	lvl = static_cast<Map::Level>(intVal);
	return is;
}

std::ostream& operator<< (std::ostream &os, const Map::Level &lvl)
{
	switch (lvl) {
	case Map::Level::EASY: return os << "Easy";
	case Map::Level::MEDIUM: return os << "Medium";
	case Map::Level::HARD: return os << "Hard";
	}
}

Map::Map()
{
	std::cout << "\nChoose a difficulty:\n\n1 - EASY *\n2 - MEDIUM **\n3 - HARD ***\n" << std::endl;
	std::cin >> difficulty; //el jugador introdueix la dificultat

	numRows = (30 - 7 * static_cast<int>(difficulty)) + rand() % (31 - 5 * static_cast<int>(difficulty) - (30 - 7 * static_cast<int>(difficulty))); //crea nombre de files i columnes segons la dificultat escollida
	numColumns = (9 + 5 * static_cast<int>(difficulty)) + rand() % (10 + 7 * static_cast<int>(difficulty) - (9 + 5 * static_cast<int>(difficulty)));

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
}

void Map::createZombie(int num)
{
	for (int i = 0; i < num; i++)
	{
		zombie randomZombie{ 65 + rand() % (91 - 65), 0, rand() % (numColumns + 1) };
		while (getCharMatrix(0, randomZombie.y) != '.')
		{
			randomZombie.y = rand() % (numColumns + 1);
		}
		//zombies.insert({ randomZombie.name + 32, randomZombie }); // Afegir a la STL
		mapMatrix[randomZombie.x][randomZombie.y] = randomZombie.name;
	}
}

void Map::killZombie(char letter)
{
	
	/*if (zombies.find(letter))
	{
		modifyMap(zombies.find.first(letter).x, zombies.find.first(letter).y, '.');
		zombies.erase(zombies.find.first(letter));
	}*/
	
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
	for (int i = 0; i < numColumns; i++)
	{
		if (getCharMatrix(numColumns, i) != '.')
			return true;
		else
			return false;
	}
}

Map::~Map()
{
}
