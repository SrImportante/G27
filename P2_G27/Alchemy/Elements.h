#pragma once

std::ifstream elementsFile("elements.dat");

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
class Elements {
	Elements();
	std::string resultCombination(std::string element1, std::string element2);
};

