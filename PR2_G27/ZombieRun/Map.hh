#pragma once
#include <map>

/*struct coordinateHash
{
	size_t operator()(const std::pair<char, int> &c) const
	{
		return ((std::hash<char>()(c.first)
			^ (std::hash<int>()(c.second) << 1)) >> 1);
	}
};*/

struct zombie
{
	char name;
	int x, y;
};


class Map
{
private:
	int numRows, numColumns;
	char **mapMatrix;
	std::map<char, int> zombies;
	int zombiesKilled;
	int numZombie;
public:
	Map(int diff);
	void printMap();
	void modifyMap(int &x, int &y, char element);
	char getCharMatrix(int x, int y);
	void createZombie(int num);
	int killZombies(char letter); //retorna el numero de zombies morts
	bool zombiesWin();
	void moveZombies();
	~Map();
};

