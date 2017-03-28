#pragma once

class CoinManager
{
private:
	int coins;
	Map *map; //Relació d'associació
public:
	CoinManager(Map *map2);
	void generateCoins(int numCoins);
	bool anyCoin();
	void pickCoin();
};