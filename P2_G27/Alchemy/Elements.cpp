#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>


class Elements
{
public:
	std::ifstream f_elemnts;
	std::string line;
	std::unordered_map<std::string, std::string> elementsMap;

	Elements()
	{
		std::f_elemnts.open("elements.dat");

		while (std::getline(f_elemnts, line))
		{
			std::string mapKey;
			std::string mapValor;

			mapValor = f_elemnts 

			elementsMap[] = 



		};

	};


};
	
