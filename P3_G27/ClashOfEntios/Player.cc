#include "Player.hh"
#include "Map.hh"
#include <iostream>
#include <queue>
#include <vector>
#include <map>

Player::Player(Map *map2, int numPlayer)
{
	map = map2;
	actions = 10;
	numEntios = 6;
	lastElement = '.';
	//std::priority_queue<Entio, std::vector<Entio>, Entio> pq;
	if (numPlayer == 1)
	{
		entios ["A"] = { 'A', 0, 10, 10 };
		entios ["B"] = { 'B', 0, 10, 10 };
		entios ["C"] = { 'C', 0, 10, 10 };
		entios ["D"] = { 'D', 0, 10, 10 };
		entios ["E"] = { 'E', 0, 10, 10 };
		entios ["F"] = { 'F', 0, 10, 10 };
		pq.push(entios["A"]);
		pq.push(entios["B"]);
		pq.push(entios["C"]);
		pq.push(entios["D"]);
		pq.push(entios["E"]);
		pq.push(entios["F"]);
	}
	else
	{
		entios ["1"] = { '1', 0, 10, 10 };
		entios ["2"] = { '2', 0, 10, 10 };
		entios ["3"] = { '3', 0, 10, 10 };
		entios ["4"] = { '4', 0, 10, 10 };
		entios ["5"] = { '5', 0, 10, 10 };
		entios ["6"] = { '6', 0, 10, 10 };
		pq.push(entios["1"]);
		pq.push(entios["2"]);
		pq.push(entios["3"]);
		pq.push(entios["4"]);
		pq.push(entios["5"]);
		pq.push(entios["6"]);
	}
}

void Player::movePlayer(enti::InputKey button)
{
	x = map->getX(pq.top().name);
	y = map->getY(pq.top().name);
	colorControl();
	
	switch (button)
	{
	case enti::InputKey::A:
		if (map->getCharMatrix(x,y-1) == ':' || map->getCharMatrix(x, y - 1) == '.')
		{
			map->modifyMap(x, y, lastElement); //Modificar segons . o :
			lastElement = map->getCharMatrix(x, y - 1);
			y--;
			addFatigue(pq.top().name, 1); // Afegir 1 de fatiga
		}
		break;
	case enti::InputKey::D:
		if (map->getCharMatrix(x, y + 1) == ':' || map->getCharMatrix(x, y + 1) == '.')
		{
			map->modifyMap(x, y, lastElement); //Modificar segons . o :
			lastElement = map->getCharMatrix(x, y + 1);
			y++;
			addFatigue(pq.top().name, 1); // Afegir 1 de fatiga
		}
		break;
	case enti::InputKey::S:
		if (map->getCharMatrix(x + 1, y) == ':' || map->getCharMatrix(x + 1, y) == '.')
		{
			map->modifyMap(x, y, lastElement); //Modificar segons . o :
			lastElement = map->getCharMatrix(x + 1, y);
			x++;
			addFatigue(pq.top().name, 1); // Afegir 1 de fatiga
		}
		break;
	case enti::InputKey::W:
		if (map->getCharMatrix(x - 1, y) == ':' || map->getCharMatrix(x - 1, y) == '.')
		{
			map->modifyMap(x, y, lastElement); //Modificar segons . o :
			lastElement = map->getCharMatrix(x - 1, y);
			x--;
			addFatigue(pq.top().name, 1); // Afegir 1 de fatiga
		}
		break;
	}
	map->modifyMap(x, y, pq.top().name);
	actions--;
};

void Player::playerAttackSword(enti::InputKey button)
{
	switch (button)
	{
		case enti::InputKey::NUM1:
		{
			if (map->getCharMatrix(x, y + 1) != ':' || map->getCharMatrix(x, y + 1) != '.' || map->getCharMatrix(x, y + 1) != 'O' || map->getCharMatrix(x, y + 1) != 'X')
			{

			}
			else
			{
				std::cout << "you failed" << std::endl;
			}
			break;
		}
		case enti::InputKey::NUM2:
		{

			break;
		}
		case enti::InputKey::NUM3:
		{

			break;
		}
		case enti::InputKey::NUM4:
		{

			break;
		}
	};

}

bool Player::allDead()
{
	return numEntios == 0;
};

int Player::getActions()
{
	return actions;
}

void Player::setActions(int num)
{
	actions =+ num;
}

void Player::switchEntio()
{
	actions--;
	char name = pq.top().name;
	pq.pop();
	switch (name)
	{
	case 'A':
		pq.push(entios["A"]);
		break;
	case 'B':
		pq.push(entios["B"]);
		break;
	case 'C':
		pq.push(entios["C"]);
		break;
	case 'D':
		pq.push(entios["D"]);
		break;
	case 'E':
		pq.push(entios["E"]);
		break;
	case 'F':
		pq.push(entios["F"]);
		break;
	case '1':
		pq.push(entios["1"]);
		break;
	case '2':
		pq.push(entios["2"]);
		break;
	case '3':
		pq.push(entios["3"]);
		break;
	case '4':
		pq.push(entios["4"]);
		break;
	case '5':
		pq.push(entios["5"]);
		break;
	case '6':
		pq.push(entios["6"]);
		break;
	}
}

void Player::addFatigue(char name, int numF)
{
	switch (name)
	{
	case 'A':
		entios["A"].fatigue += numF;
		break;
	case 'B':
		entios["B"].fatigue += numF;
		break;
	case 'C':
		entios["C"].fatigue += numF;
		break;
	case 'D':
		entios["D"].fatigue += numF;
		break;
	case 'E':
		entios["E"].fatigue += numF;
		break;
	case 'F':
		entios["F"].fatigue += numF;
		break;
	case '1':
		entios["1"].fatigue += numF;
		break;
	case '2':
		entios["2"].fatigue += numF;
		break;
	case '3':
		entios["3"].fatigue += numF;
		break;
	case '4':
		entios["4"].fatigue += numF;
		break;
	case '5':
		entios["5"].fatigue += numF;
		break;
	case '6':
		entios["6"].fatigue += numF;
		break;
	}
}
void Player::colorControl()
{
	if (map->getCharMatrix(x, y) == pq.top().name)
		map->magentaEntio = true;
	else 
		map->yellowEntio = true;
}