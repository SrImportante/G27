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
	entiosAlive = 6;
	lastElement = '.';
	//std::priority_queue<Entio, std::vector<Entio>, Entio> pq;
	if (numPlayer == 1)
	{
		entios ['A'] = { 'A', 0, 10, 10 }; // name, fatigue, life, arrow
		entios ['B'] = { 'B', 0, 10, 10 }; // name, fatigue, life, arrow
		entios ['C'] = { 'C', 0, 10, 10 }; // name, fatigue, life, arrow
		entios ['D'] = { 'D', 0, 10, 10 }; // name, fatigue, life, arrow
		entios ['E'] = { 'E', 0, 10, 10 }; // name, fatigue, life, arrow
		entios ['F'] = { 'F', 0, 10, 10 }; // name, fatigue, life, arrow
		pq.push(entios['A']);
		pq.push(entios['B']);
		pq.push(entios['C']);
		pq.push(entios['D']);
		pq.push(entios['E']);
		pq.push(entios['F']);
	}
	else
	{
		entios ['1'] = { '1', 0, 10, 10 }; // name, fatigue, life, arrow
		entios ['2'] = { '2', 0, 10, 10 }; // name, fatigue, life, arrow
		entios ['3'] = { '3', 0, 10, 10 }; // name, fatigue, life, arrow
		entios ['4'] = { '4', 0, 10, 10 }; // name, fatigue, life, arrow
		entios ['5'] = { '5', 0, 10, 10 }; // name, fatigue, life, arrow
		entios ['6'] = { '6', 0, 10, 10 }; // name, fatigue, life, arrow
		pq.push(entios['1']);
		pq.push(entios['2']);
		pq.push(entios['3']);
		pq.push(entios['4']);
		pq.push(entios['5']);
		pq.push(entios['6']);
	}
}

void Player::movePlayer(enti::InputKey button)
{
	x = map->getX(pq.top().name);
	y = map->getY(pq.top().name);
	colorControl();
	
	switch (button)
	{
	case enti::InputKey::A: case enti::InputKey::a:
		if (map->getCharMatrix(x,y - 1) == ':' || map->getCharMatrix(x, y - 1) == '.')
		{
			map->modifyMap(x, y, lastElement); //Modificar segons . o :
			lastElement = map->getCharMatrix(x, y - 1);
			y--;
			addFatigue(pq.top().name, 1); // Afegir 1 de fatiga
			actions--;
		}
		break;
	case enti::InputKey::D: case enti::InputKey::d:
		if (map->getCharMatrix(x, y + 1) == ':' || map->getCharMatrix(x, y + 1) == '.')
		{
			map->modifyMap(x, y, lastElement); //Modificar segons . o :
			lastElement = map->getCharMatrix(x, y + 1);
			y++;
			addFatigue(pq.top().name, 1); // Afegir 1 de fatiga
			actions--;
		}
		break;
	case enti::InputKey::S: case enti::InputKey::s:
		if (map->getCharMatrix(x + 1, y) == ':' || map->getCharMatrix(x + 1, y) == '.')
		{
			map->modifyMap(x, y, lastElement); //Modificar segons . o :
			lastElement = map->getCharMatrix(x + 1, y);
			x++;
			addFatigue(pq.top().name, 1); // Afegir 1 de fatiga
			actions--;
		}
		break;
	case enti::InputKey::W: case enti::InputKey::w:
		if (map->getCharMatrix(x - 1, y) == ':' || map->getCharMatrix(x - 1, y) == '.')
		{
			map->modifyMap(x, y, lastElement); //Modificar segons . o :
			lastElement = map->getCharMatrix(x - 1, y);
			x--;
			addFatigue(pq.top().name, 1); // Afegir 1 de fatiga
			actions--;
		}
		break;
	}
	map->modifyMap(x, y, pq.top().name);
};

void Player::playerAttackSword(enti::InputKey button, bool turn1, Player &enemie)
{
	x = map->getX(pq.top().name);
	y = map->getY(pq.top().name);
	switch (button)
	{
		case enti::InputKey::NUM1: // UP
		{
			if (turn1)
			{
				if (map->getCharMatrix(x - 1, y) == '1' || map->getCharMatrix(x - 1, y) == '2' || map->getCharMatrix(x - 1, y) == '3' || map->getCharMatrix(x - 1, y) == '4'
					|| map->getCharMatrix(x - 1, y) == '5' || map->getCharMatrix(x - 1, y) == '6')
				{
					enemie.entioLoseLife(map->getCharMatrix(x - 1, y), 10);
					map->modifyMap(x - 1, y, '.');
				}
				else
				{
					std::cout << "you failed" << std::endl;
				}
			}
			else
			{
				if (map->getCharMatrix(x - 1, y) == 'A' || map->getCharMatrix(x - 1, y) == 'B' || map->getCharMatrix(x - 1, y) == 'C' || map->getCharMatrix(x - 1, y) == 'D'
					|| map->getCharMatrix(x - 1, y) == 'E' || map->getCharMatrix(x - 1, y) == 'F')
				{
					enemie.entioLoseLife(map->getCharMatrix(x - 1, y), 10);
					map->modifyMap(x - 1, y, '.');
				}
				else
				{
					std::cout << "you failed" << std::endl;
				}
			}
			break;
		}
		case enti::InputKey::NUM2: //LEFT
		{
			if (turn1)
			{
				if (map->getCharMatrix(x, y - 1) == '1' || map->getCharMatrix(x, y - 1) == '2' || map->getCharMatrix(x, y - 1) == '3' || map->getCharMatrix(x, y - 1) == '4'
					|| map->getCharMatrix(x, y - 1) == '5' || map->getCharMatrix(x, y - 1) == '6')
				{
					enemie.entioLoseLife(map->getCharMatrix(x, y - 1), 10);
					map->modifyMap(x, y - 1, '.');
				}
				else
				{
					std::cout << "you failed" << std::endl;
				}
			}
			else
			{
				if (map->getCharMatrix(x, y - 1) == 'A' || map->getCharMatrix(x, y - 1) == 'B' || map->getCharMatrix(x, y - 1) == 'C' || map->getCharMatrix(x, y - 1) == 'D'
					|| map->getCharMatrix(x, y - 1) == 'E' || map->getCharMatrix(x, y - 1) == 'F')
				{
					enemie.entioLoseLife(map->getCharMatrix(x, y - 1), 10);
					map->modifyMap(x, y - 1, '.');
				}
				else
				{
					std::cout << "you failed" << std::endl;
				}
			}
			break;
		}
		case enti::InputKey::NUM3: //DOWN
		{
			if (turn1)
			{
				if (map->getCharMatrix(x + 1, y) == '1' || map->getCharMatrix(x + 1, y) == '2' || map->getCharMatrix(x + 1, y) == '3' || map->getCharMatrix(x + 1, y) == '4'
					|| map->getCharMatrix(x + 1, y) == '5' || map->getCharMatrix(x + 1, y) == '6')
				{
					enemie.entioLoseLife(map->getCharMatrix(x + 1, y), 10);
					map->modifyMap(x + 1, y, '.');
				}
				else
				{
					std::cout << "you failed" << std::endl;
				}
			}
			else
			{
				if (map->getCharMatrix(x + 1, y) == 'A' || map->getCharMatrix(x + 1, y) == 'B' || map->getCharMatrix(x + 1, y) == 'C' || map->getCharMatrix(x + 1, y) == 'D'
					|| map->getCharMatrix(x + 1, y) == 'E' || map->getCharMatrix(x + 1, y) == 'F')
				{
					enemie.entioLoseLife(map->getCharMatrix(x + 1, y), 10);
					map->modifyMap(x + 1, y, '.');
				}
				else
				{
					std::cout << "you failed" << std::endl;
				}
			}
			break;
		}
		case enti::InputKey::NUM4: //RIGHT
		{
			if (turn1)
			{
				if (map->getCharMatrix(x, y + 1) == '1' || map->getCharMatrix(x, y + 1) == '2' || map->getCharMatrix(x, y + 1) == '3' || map->getCharMatrix(x, y + 1) == '4'
					|| map->getCharMatrix(x, y + 1) == '5' || map->getCharMatrix(x, y + 1) == '6')
				{
					enemie.entioLoseLife(map->getCharMatrix(x, y + 1), 10);
					map->modifyMap(x, y + 1, '.');
				}
				else
				{
					std::cout << "you failed" << std::endl;
				}
			}
			else
			{
				if (map->getCharMatrix(x, y + 1) == 'A' || map->getCharMatrix(x, y + 1) == 'B' || map->getCharMatrix(x, y + 1) == 'C' || map->getCharMatrix(x, y + 1) == 'D'
					|| map->getCharMatrix(x, y + 1) == 'E' || map->getCharMatrix(x, y + 1) == 'F')
				{
					enemie.entioLoseLife(map->getCharMatrix(x, y + 1), 10);
					map->modifyMap(x, y + 1, '.');
				}
				else
				{
					std::cout << "you failed" << std::endl;
				}
			}
			break;
		}
	};
	actions--;
}

void Player::entioLoseLife(char name, int dmg)
{
	entios[name].life = entios[name].life - dmg;
	if (entios[name].life <= 0)
	{
		entiosAlive--;
	}
	std::cout << "Entio " << entios[name].name << " te " << entios[name].life << std::endl;
	_getch();
}

bool Player::allDead()
{
	return entiosAlive == 0;
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
	pq.push(entios[name]);
}

void Player::addFatigue(char name, int numF)
{
	entios[name].fatigue += numF;
}

void Player::colorControl()
{
	if (map->getCharMatrix(x, y) == pq.top().name)
		map->magentaEntio = true;
	else 
		map->yellowEntio = true;
}