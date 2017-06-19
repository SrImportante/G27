#include <iostream>
#include <ctime>
#include <stdio.h>      
#include <stdlib.h> 
#include <time.h>  
#include "Input.inl.hh"
#include "Player.hh" 
#include "Map.hh"



int main()
{
	
	srand(time(NULL));

	Map *myMap = new Map();
	system("cls");
	clock_t timeCounter = 0; // clock tick timer

	myMap->zombiesComing();


	_getch();
	_getch();
	return 0;
}
