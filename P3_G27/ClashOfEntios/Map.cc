#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include "Map.hh"

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

void Map::printMap() //funci� per imprimir l'array din�mica
{
	for (int i{ 0 }; i < numRows; i++)
	{
		for (int j{ 0 }; j < numColumns - 1; j++)
		{
			std::cout << mapMatrix[i][j];
		}
		std::cout << std::endl;
	}
}

void Map::modifyMap(int &x, int &y, char element) //canvia el car�cter de la cel�la en que es troba el jugador
{
	mapMatrix[x][y] = element;
}

int Map::getX(char element) //funci� per imprimir l'array din�mica
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

int Map::getY(char element) //funci� per imprimir l'array din�mica
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

char Map::getCharMatrix(int x, int y) //funci� per retornar el car�cter que es troba en la cel�la
{
	return mapMatrix[x][y];
}