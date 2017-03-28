#pragma once

class CoinManager
{
private:
	int coins;
	Map *map; //Relaci� d'associaci�
public:
	CoinManager(Map *map2);
	void generateCoins(int numCoins);
	bool anyCoin();
	void pickCoin();
};