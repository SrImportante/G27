#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

#include "Elements.cpp"

#include "Elements.h"
#include "Player.h"

#include <windows.h>

class Player
{
public:
	Elements m_list;
	int score;
	std::vector<std::string> elementsList;

	Player(Elements list);

	void userInput();
	void combine(int a, int b);
	void add(int a);
	void deleteE(int a);
	void addBasics();
	void sort();
	void clean();
	void showElementsList();
	void help();


};


Player::Player(Elements list)
{
	m_list = list;

	elementsList.push_back("aire");
	elementsList.push_back("fuego");
	elementsList.push_back("tierra");
	elementsList.push_back("agua");
	score = 0;
}


void Player::userInput()
{
	std::string input;
	int a, b;

	std::cin >> input;

	//Per fer una copia
		std::string addInput = "add";
		if (input == addInput)
		{
			std::cin >> a;
			add(a);
		}

	//Afegir els elements basics
		std::string basicsInput = "add basics";
		if (input == basicsInput)
		{
			addBasics();
		}

	//Eliminar un element
		std::string deleteInput = "add";
		if (input == deleteInput)
		{
			std::cin >> a;
			deleteE(a);
		}

	//Buscar infomaci� al Wikipedia
		/*
		const char* urlB = "http://www.cplusplus.com/";
		wchar_t urlW[ MAX_PATH ];
		std::copy( urlB, urlB + lstrlenA( urlB ) + 1, urlW );
		if ((int)ShellExecuteW( NULL, L"open", urlW, NULL, NULL, SW_SHOW ) < 32);
		*/

	//Ordena tots els elements per ordre alfab�tic
		std::string sortInput = "add";
		if (input == sortInput)
		{
			sort();
		}

	//Per la combinaci� d'elements
		else
		{
			std::cin >> a >> b;
			combine(a, b);
		}
}

void Player::add(int a)
{
	elementsList.push_back(elementsList.at(a));
}

void Player::addBasics()
{
	elementsList.push_back("aire");
	elementsList.push_back("fuego");
	elementsList.push_back("tierra");
	elementsList.push_back("agua");
}

void Player::deleteE(int a)
{
	elementsList.erase(elementsList.begin() + a - 1);
}

void Player::sort()
{
	
	std::sort(elementsList.begin(), elementsList.end());
	
}

void Player::clean()
 {
	for (unsigned int i = 0; i <= elementsList.size() - 1; i++)
		 {
		for (unsigned int j = 0; j <= elementsList.size() - 1; j++)
			 {
			if (elementsList.at(i) == elementsList.at(j))
				 {
				elementsList.erase(elementsList.begin() + j - 1);
				}
			}
		}
}

void Player::help()
 {
	std::cout << "------------------\nFULLENTI ALCHEMIST\n------------------\n"
		 << "- Enter two numbers of your elements list to combine them.\n"
		 << "- Enter the word 'add' and the number of an element to add a new instance of that element.\n"
		 << "- Enter 'add basics' to add new instances of the 4 basic elements.\n"
		 << "- Enter the word 'delete' and the number of an element to erase it from your list.\n"
		 << "- Enter the word 'info' and the number of an element to get information about it in the explorer.\n"
		 << "- Enter the word 'sort' to sort by alphabetical order the elements in the list.\n"
		 << "- Enter the word 'clean' to delete all the instances of repeated elements.\n"
		 << "- Enter the word 'help' to show this tutorial.\n" << std::endl;
	
		}

void Player::combine(int a, int b)
{
	std::string element1, element2;

	element1 = elementsList.at(a);
	element2 = elementsList.at(b);

	if (a > b)
	{
		elementsList.erase(elementsList.begin() + a - 1);
		elementsList.erase(elementsList.begin() + b - 1);
	}
	if (a < b)
	{
		elementsList.erase(elementsList.begin() + b - 1);
		elementsList.erase(elementsList.begin() + a - 1);
	}
	else
		std::cout << "Error, There is no possible combination" << std::endl;

	elementsList.push_back(m_list.resultCombination(element1, element2));
	if (m_list.resultCombination(element1, element2) == "noElement")
	{
		elementsList.pop_back();
	}
	//sumar score
}

//Ense�ar h
 void Player::showElementsList()
{
	for (std::vector<std::string>::iterator it = elementsList.begin(); it != elementsList.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
}
