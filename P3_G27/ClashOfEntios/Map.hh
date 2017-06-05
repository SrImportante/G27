#pragma once

class Map
{
private:
	char **mapMatrix;
	int numRows, numColumns;// 36x74;
public:
	bool magentaEntio;
	bool yellowEntio;
	Map(void);
	void printMap();
	void printMapPlayers(int i, int j);
	void modifyMap(int x, int y, char element);
	int getX(char element);
	int getY(char element);
	char getCharMatrix(int x, int y); //funció per retornar el caràcter que es troba en la cel·la
};