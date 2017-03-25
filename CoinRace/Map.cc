#include <iostream>
#include <stdio.h>
#include "Map.hh"

std::istream& operator>> (std::istream &is, Map::Level &lvl)
{
	int intVal;
	is >> intVal;
	lvl = static_cast<Map::Level>(intVal);
	return is;
}

std::ostream& operator<< (std::ostream &os, const Map::Level &lvl) 
{
	switch (lvl) {
	case Map::Level::EASY: return os << "easy";
	case Map::Level::MEDIUM: return os << "medium";
	case Map::Level::HARD: return os << "hard";
	}
}

Map::Map()
{
	std::cout << "Introdueix un nivell:\n\n1.Facil\n2.Normal\n3.Dificil\n" << std::endl;
	std::cin >> difficulty;

	numRows = 5 * static_cast<int>(difficulty);
	numColumns = 5 * static_cast<int>(difficulty) * 2;

	mapMatrix = new char*[numRows]; //Crea una array dinamica de punters a chars (filas)

	for (int i{ 0 }; i < numRows; i++)
	{
		mapMatrix[i] = new char[numColumns]; //Cada punter esta apuntant a una array dinamica de chars (coumnes)
		for (int j{ 0 }; j < numColumns; j++)
		{
			mapMatrix[i][j] = '.';
		}
	}
}

//x i y son la posicio del jugador, i element el char que ha de posar
void Map::modifyMap(int &x, int &y, char element)
{
	mapMatrix[x][y] = element;
}

void Map::printMap()
{
	for (int i{ 0 }; i < numRows; i++)
	{
		for (int j{ 0 }; j < numColumns; j++)
		{
			std::cout << mapMatrix[i][j];
		}
		std::cout << std::endl;
	}
}

int Map::getRows()
{
	return numRows;
}

int Map::getColumns()
{
	return numColumns;
}

char Map::getCharMatrix(int &x, int &y)
{
	return mapMatrix[x][y];
}

void Map::deleteMatrix()
{
	for (int i{ 0 }; i < numRows; i++)
	{
		delete[]mapMatrix[i];
	}
	delete[]mapMatrix;
}