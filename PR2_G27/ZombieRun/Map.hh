#pragma once
#include <unordered_map>


struct coordinateHash
{
	size_t operator()(const std::pair<char, char> &c) const
	{
		return ((std::hash<char>()(c.first)
			^ (std::hash<char>()(c.second)) << 1)) >> 1;
	}
};

struct zombie
{
	char name;
	int x, y;
};


class Map
{
private:
	enum class Level { EASY = 1, MEDIUM, HARD };
	Level difficulty;
	int numRows, numColumns;
	char **mapMatrix;
	std::unordered_map < std::pair<char, char>, zombie, coordinateHash> zombies;
	int zombiesKilled;
public:
	Map();
	void printMap();
	void createZombie();
	void killZombie();
	void zombiesComing();
	bool zombiesWin();
	friend std::istream& operator >> (std::istream &is, Level &lvl);
	friend std::ostream& operator<< (std::ostream &os, const Level &lvl);
	~Map();
};

