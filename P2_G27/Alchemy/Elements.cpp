#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include "Elements.h"

class Elements
{
	
	Elements()
	{
		while (getline(elementsFile, line))
		{
			std::string elementResult = line.substr(0, line.find("=") - 1);
			std::string elementFirst = line.substr(line.find("=") + 2, line.find("+") - line.find("=") - 3);
			std::string elementSecond = line.substr(line.find("+") + 2, line.size());

			elementsMap.insert({ { elementFirst, elementSecond }, elementResult });

		}
	};

public:
	std::string resultCombination(std::string element1, std::string element2);


};

std::string Elements::resultCombination(std::string element1, std::string element2)
{

	if (elementsMap.find({ element1, element2 }) == elementsMap.end())
	{
		std::cout << "Error, There is no possible combination" << std::endl;
	}

	else
	{
		return elementsMap[{element1, element2}];
	}

	if (elementsMap.find({ element2, element1 }) == elementsMap.end())
	{
		std::cout << "Error, There is no possible combination" << std::endl;
	}

	else
	{
		return elementsMap[{element2, element1}];
	}

}
	
