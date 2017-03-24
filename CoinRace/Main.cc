#include <iostream>
#include <stdio.h>
#include "Map.hh"
#include "CoinManager.hh"

int main()
{
	Map myMap;
	int x = 3, y = 3;
	char c = '@';
	myMap.modifyMap( x, y, c);
	CoinManager myCoin(myMap);
	return 0;
}