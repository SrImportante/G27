#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include "Elements.h"
#include "Elements.cpp"
#include "Player.h"
#include "Player.cpp"






int main()
{
	Elements guide();
	Player player();

	std::cout << "//////////////////////////" << std::endl;
	std::cout << "FULLENTI ALCHEMIST" << std::endl;
	std::cout << "//////////////////////////" << std::endl;
	std::cout << "- Enter two numbers of your elements list to combine them." << std::endl;
	std::cout << "- Enter the word 'add' and the number of element to add a new instance of that element." << std::endl;
	std::cout << "- Enter 'add basics' to add new instance of the 4 basic elements." << std::endl;
	std::cout << "- Enter the word 'delete' and the number of an element to erase it from your list." << std::endl;
	std::cout << "- Enter the word 'info' and the number of an element to get information about it in the explorer." << std::endl;
	std::cout << "- Enter the word 'sort' to sort by alphabetical order the elements in the list." << std::endl;
	std::cout << "- Enter the word 'clean' to delete all the instances of repeated elements." << std::endl;
	std::cout << "- Enter the word 'help' to show this tutorial." << std::endl;
	
	std::cout << "\nYour current score:"<< player().score << std::endl;
	
	system("cls");
	return 0;
}