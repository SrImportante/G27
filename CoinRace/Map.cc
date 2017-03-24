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
	}}
Map::Map()
{
	Level dificult;

	std::cout << "Introdueix un nivell: \nFacil: 1\nNormal: 2\nDificil: 3\n\n" << std::endl;
	std::cin >> dificult;
	
	const int FILAS{ 5 * static_cast<int>(dificult) };
	const int COLUM{ 5 * static_cast<int>(dificult) * 2 };
	MapMatrix = new char[FILAS][COLUM];

	for (int i = 0; i < 5 * static_cast<int>(dificult); i++)
	{
		for (int j = 0; j < 5 * static_cast<int>(dificult) * 2; j++)
		{
			MapMatrix[i][j] = '*';
			std::cout << MapMatrix[i][j];
		}
		std::cout << std::endl;
	}
};

//x i y son la posicio del jugador, i element el char que ha de posar
void Map::modify(int &x, int &y, char &element)
{
	MapMatrix[x][y] = element;
}


