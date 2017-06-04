#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include "Map.hh"
#include "Renderer.hh"
#include "Player.hh"

Map::Map()
{
	numRows = 36;
	numColumns = 74;
	int i = -1, j = numColumns;
	char line;
	mapMatrix = new char*[numRows];

	std::ifstream fentrada("default.cfg");
	if (fentrada.is_open())
	{
		while (!fentrada.eof())
		{
			if (j >= numColumns - 1)
			{
				i++;
				mapMatrix[i] = new char[numColumns];
				j = 0;
			}
			fentrada >> line;
			mapMatrix[i][j] = line;
			j++;
		}
	}
	else std::cout << "Unable to open file";

	fentrada.close();
}

void Map::printMap() //funció per imprimir l'array dinàmica
{
	for (int i{ 0 }; i < numRows; i++)
	{
		for (int j{ 0 }; j < numColumns - 1; j++)
		{
			if (mapMatrix[i][j] == 'O')
				enti::cout << enti::Color::LIGHTCYAN << mapMatrix[i][j] << " ";

			else if (mapMatrix[i][j] == 'X')
				enti::cout << enti::Color::RED << mapMatrix[i][j] << " ";

			else if (mapMatrix[i][j] == '.')
				enti::cout << enti::Color::WHITE << mapMatrix[i][j] << " ";

			else if (mapMatrix[i][j] == ':')
				enti::cout << enti::Color::GREEN << mapMatrix[i][j] << " ";

			else
				printMapPlayers(i, j);
		}
		enti::cout << enti::endl;
	}
	enti::cout << enti::cend;
}

//no em surt );
void Map::printMapPlayers(int i, int j)
{
	if (magentaEntio)
	{
		enti::cout << enti::Color::LIGHTMAGENTA << mapMatrix[i][j] << " ";
		magentaEntio = false;
	}
	else if (yellowEntio)
		enti::cout << enti::Color::YELLOW << mapMatrix[i][j] << " ";
	else
		enti::cout << enti::Color::DARKGRAY << mapMatrix[i][j] << " ";
}

void Map::modifyMap(int &x, int &y, char element) //canvia el caràcter de la cel·la en que es troba el jugador
{
	mapMatrix[x][y] = element;
}

int Map::getX(char element) //funció per imprimir l'array dinàmica
{
	int x;
	for (int i{ 0 }; i < numRows; i++)
	{
		for (int j{ 0 }; j < numColumns - 1; j++)
		{
			if (mapMatrix[i][j] == element)
			{
				x = i;
			}
		}
	}
	return x;
}

int Map::getY(char element) //funció per imprimir l'array dinàmica
{
	int y;
	for (int i{ 0 }; i < numRows; i++)
	{
		for (int j{ 0 }; j < numColumns - 1; j++)
		{
			if (mapMatrix[i][j] == element)
			{
				y = j;
			}
		}
	}
	return y;
}

char Map::getCharMatrix(int x, int y) //funció per retornar el caràcter que es troba en la cel·la
{
	return mapMatrix[x][y];
}