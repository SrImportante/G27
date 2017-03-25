#pragma once

class Map
{
private:
	enum class Level { EASY=1, MEDIUM, HARD };
	Level difficulty;
	int numRows, numColumns;
	char **mapMatrix; //Matriu dinàmica

public:
	//constructor
	Map(void);

	void modifyMap(int &x, int &y, char element);
	void printMap();
	int getRows();
	int getColumns();
	char getCharMatrix(int &x, int &y);
	void deleteMatrix();
	int getLevel();
	friend std::istream& operator>> (std::istream &is, Level &lvl);
	friend std::ostream& operator<< (std::ostream &os, const Level &lvl);
};