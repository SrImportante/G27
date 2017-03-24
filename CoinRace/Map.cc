#include <iostream>
#include <stdio.h>

#include "Map.hh"


class Map
{
private:
	enum class Level { Easy, Medium, Hard };
	char MapMatrix[15][30];  //ha d'estar en el heap (new)

public:
	Map::Map()
	{
		for (int i = 0; i < 5 * static_cast<int>(Map::setLevel()); i++) 
		{
			for (int j = 0; i < 5 * static_cast<int>(Map::setLevel()) * 2; j++)
			{
				MapMatrix[i][j] = '*';
				std::cout << MapMatrix[i][j];
			}

			std::cout << "\n";

		}
	};
	
	Level Map::setLevel() 
	{
		Level level;
		int input;
	std::cout << "Introdueix un nivell: \n\nFacil: 1\nNormal: 2\nDificil: 3\n\n" << std::endl;
	std::cin >> input;
	level = static_cast<Level>(input);
	return level;
    }

	//x i y son la posicio del jugador, i element el char que ha de posar
	void Map::modify(int &x, int &y, char &element)
	{
		MapMatrix[x][y] = element;
	}
};