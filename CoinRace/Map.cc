#include <iostream>
#include <stdio.h>


class Map
{
private:
	enum class Level { Easy, Medium, Hard };
	char MapMatrix[15][30];

public:
	/*Map::Map() :

		//for (int i = 0; i < 5 * static_cast<int>(Level); i++) {}
	{};
	*/
	Level Map::setLevel() 
	{
		Level level;
		int input;
	std::cout << "Introdueix un nivell: \n\nFacil: 1\nNormal: 2\nDificil: 3" << std::endl;
	std::cin >> input;
	level = static_cast<Level>(input);
	return level;
    }

	//Map::modiMap(x, y, )
};