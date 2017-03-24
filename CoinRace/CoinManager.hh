#pragma once
#include "Map.hh"

class CoinManager
{
private:
	int coins;
public:
	CoinManager(Map& map);
	void deleteCoin(int &x, int &y, Map& map);
	void generateCoins(Map& map, int numCoins);
};