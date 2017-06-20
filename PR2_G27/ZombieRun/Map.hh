#pragma once
#include <unordered_map>

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
	enum class Level { EASY = 1, MEDIUM, HARD };
	Level difficulty;
	int numRows, numColumns;
	char **mapMatrix;
	std::unordered_map <char, zombie> zombies;
	int zombiesKilled;
	int numZombie;
public:
	Map();
	void printMap();
	void modifyMap(int &x, int &y, char element);
	char getCharMatrix(int x, int y);
	void createZombie(int num);
	void killZombie(char letter);
	bool zombiesWin();
	void moveZombies();
	friend std::istream& operator >> (std::istream &is, Level &lvl);
	friend std::ostream& operator<< (std::ostream &os, const Level &lvl);
	~Map();
};

