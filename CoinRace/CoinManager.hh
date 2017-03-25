#pragma once
#include "Map.hh"

class CoinManager
{
private:
	int coins;
	Map map;
public:
	CoinManager(Map &map2);
	void deleteCoin(int &x, int &y);
	void generateCoins(int numCoins);
	bool anyCoin();
	void pickCoin();
};