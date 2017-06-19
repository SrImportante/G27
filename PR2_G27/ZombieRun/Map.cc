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
			mapMatrix[i][j] = '.'; //S'omple l'array din�mica de chars amb cel�les buides
		}
	}
}

void Map::printMap() //funci� per imprimir l'array din�mica
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

void Map::createZombie()
{
	zombie randomZombie{ (rand() % 91) + 65, rand() % (numColumns + 1), 0};//no se perque no fa que nom�s siguin vocals

	zombies.insert({randomZombie.name + 32, randomZombie });
	mapMatrix[randomZombie.y][randomZombie.x] = randomZombie.name;

}

void Map::killZombie(char letter)
{
	
	/*if (zombies.find(letter))
	{
		modifyMap(zombies.find.first(letter).x, zombies.find.first(letter).y, '.');
		zombies.erase(zombies.find.first(letter));
	}*/
	
}

void Map::zombiesComing()//no acava de funcionar
{
	clock_t timeCounter = 0; // clock tick timer
		while (true)
		{
			if (clock() / (CLOCKS_PER_SEC / 1000) > timeCounter + 1000)
			{
				for (int i{ 0 }; i < numRows - numRows+1; i++)
				{
					system("cls");
					printMap();
					if (clock() / (CLOCKS_PER_SEC / 1000) > timeCounter + 1000)
					{
					for (int j{ 0 }; j < numColumns; j++)
					{
						mapMatrix[i + 1][j] = mapMatrix[i][j];
						mapMatrix[i][j] = '.';
						timeCounter = clock() / (CLOCKS_PER_SEC / 1000);
					}
					}
					
				}
				createZombie();		
		}
	}

}

void Map::modifyMap(int &x, int &y, char element) //canvia el car�cter de la cel�la en que es troba el jugador
{
	mapMatrix[x][y] = element;
}

char Map::getCharMatrix(int &x, int &y) //funci� per retornar el car�cter que es troba en la cel�la
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
