class Map
{
private:
	enum class Level { EASY=1, MEDIUM, HARD };
	char *MapMatrix; //ha d'estar en el heap (new)

public:
	//constructor
	Map(void);

	//Level Map::setLevel();
	void modify(int &x, int &y, char &element);

	friend std::istream& operator>> (std::istream &is, Level &lvl);
	friend std::ostream& operator<< (std::ostream &os, const Level &lvl);
};