class Map
{
private:
	enum class Level { Easy, Medium, Hard };
	char MapMatrix[15][30];

public:
	Map::Map();
	Level Map::setLevel();
	void Map::modify(int &x, int &y, char &element);

};