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
	case Map::Level::EASY: return os << "Easy";
	case Map::Level::MEDIUM: return os << "Medium";
	case Map::Level::HARD: return os << "Hard";
	}
}

Map::Map()
{
	
	std::cout << "\nChoose a difficulty:\n\n1 - EASY *\n2 - MEDIUM **\n3 - HARD ***\n" << std::endl;
	std::cin >> difficulty; //el jugador introdueix la dificultat

	numRows = 5 * static_cast<int>(difficulty); //crea nombre de files i columnes segons la dificultat escollida
	numColumns = 5 * static_cast<int>(difficulty) * 2;

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

//x i y son la posicio del jugador, i element el char que ha de posar
void Map::modifyMap(int &x, int &y, char element) //canvia el caràcter de la cel·la en que es troba el jugador
{
	mapMatrix[x][y] = element;
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

int Map::getRows() //funció per retornar el nombre de files
{
	return numRows;
}

int Map::getColumns() //funció per retornar el nombre de columnes
{
	return numColumns;
}

char Map::getCharMatrix(int &x, int &y) //funció per retornar el caràcter que es troba en la cel·la
{
	return mapMatrix[x][y];
}

void Map::deleteMatrix() //elimina la matriu dinamica
{
	for (int i{ 0 }; i < numRows; i++)
	{
		delete[]mapMatrix[i];
	}
	delete[]mapMatrix;
}

int Map::getLevel()
{
	return static_cast<int>(difficulty);
}