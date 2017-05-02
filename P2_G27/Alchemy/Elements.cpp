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

			//std::cout << elementFirst << " + " << elementSecond << " = " << elementsMap[{elementFirst, elementSecond}] << std::endl;
		}
	};

	void resultCombination(std::string element1, std::string element2)
	{
		for (int i = 0; elementsMap.begin(i) != elementsMap.end(); i++)
		{

		}
		elementsMap.find({ element1, element2 });


	}


};
	
