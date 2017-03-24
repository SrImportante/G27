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
	case Map::Level::HARD: return os << "hard";	}}
Map::Map()
{
	Level dificult;

	std::cout << "Introdueix un nivell:\n\n1.Facil\n2.Normal\n3.Dificil\n" << std::endl;
	std::cin >> dificult;
	row =  5 * static_cast<int>(dificult);
	column = 5 * static_cast<int>(dificult) * 2;

	MapMatrix = new char*[row]; //Crea una array dinamica de punters a chars (filas)

	for (int i = 0; i < row; i++)
	{
		MapMatrix[i] = new char[column]; //Cada punter esta apuntant a una array dinamica de chars (coumnes)
		for (int j = 0; j < column; j++)
		{
			MapMatrix[i][j] = '*';
			//std::cout << MapMatrix[i][j];
		}
		//std::cout << std::endl;
	}
};

//x i y son la posicio del jugador, i element el char que ha de posar
void Map::modifyMap(int &x, int &y, char &element)
{
	MapMatrix[x][y] = element;
}

void Map::printMap()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			std::cout << MapMatrix[i][j];
		}
		std::cout << std::endl;
	}
}

int Map::getRow()
{
	return row;
}

int Map::getColumn()
{
	return column;
}
