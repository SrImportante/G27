#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include "Elements.h"


class Elements
{
public:


	std::string line;

	struct coordinateHash
	{
		size_t operator()(const std::pair<std::string, std::string> &c) const
		{
			return ((std::hash<std::string>()(c.first)
				^ (std::hash<std::string>()(c.second)) << 1)) >> 1;
		}
	};

	std::unordered_map<std::pair<std::string, std::string>, std::string, coordinateHash> elementsMap;

	Elements::Elements()
	{
		std::ifstream elementsFile("elements.dat");
		while (getline(elementsFile, line))
		{
			std::string elementResult = line.substr(0, line.find("=") - 1);
			std::string elementFirst = line.substr(line.find("=") + 2, line.find("+") - line.find("=") - 3);
			std::string elementSecond = line.substr(line.find("+") + 2, line.size());

			elementsMap.insert({ { elementFirst, elementSecond }, elementResult });

		}
	};

	std::string resultCombination(std::string element1, std::string element2);

};



std::string Elements::resultCombination(std::string element1, std::string element2)
{

	if (elementsMap.find({ element1, element2 }) == elementsMap.end())
	{
		std::cout << "Error, There is no possible combination" << std::endl;
		return "noElement";
	}

	else
	{
		return elementsMap[{element1, element2}];
	}

	if (elementsMap.find({ element2, element1 }) == elementsMap.end())
	{
		std::cout << "Error, There is no possible combination" << std::endl;
		return "noElement";
	}

	else
	{
		return elementsMap[{element2, element1}];
	}

}
	
