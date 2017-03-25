#pragma once

class CoinManager
{
private:
	int coins;
	Map map;
public:
	CoinManager(Map &map2);
	void generateCoins(int numCoins);
	bool anyCoin();
	void pickCoin();
};