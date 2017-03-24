class Map
{
private:
	enum class Level { EASY=1, MEDIUM, HARD };
	int row, column;
	char **MapMatrix; //Matriu dinàmica

public:
	//constructor
	Map(void);

	//Level Map::setLevel();
	void modifyMap(int &x, int &y, char &element);
	void printMap();
	int getRow();
	int getColumn();
	friend std::istream& operator>> (std::istream &is, Level &lvl);
	friend std::ostream& operator<< (std::ostream &os, const Level &lvl);
};