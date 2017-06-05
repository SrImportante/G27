#include "Player.hh"
#include "Map.hh"
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <stack>

Player::Player(Map *map2, int numPlayer)
{
	//map per guardar els entios amb el seu char com a key
	map = map2;
	actions = 10;
	canUndo = true;
	entiosAlive = 6;

	if (numPlayer == 1)
	{
		entios ['A'] = { 'A', 0, 10, 10, '.' }; // name, fatigue, life, arrow
		entios ['B'] = { 'B', 0, 10, 10, '.' }; // name, fatigue, life, arrow
		entios ['C'] = { 'C', 0, 10, 10, '.' }; // name, fatigue, life, arrow
		entios ['D'] = { 'D', 0, 10, 10, '.' }; // name, fatigue, life, arrow
		entios ['E'] = { 'E', 0, 10, 10, '.' }; // name, fatigue, life, arrow
		entios ['F'] = { 'F', 0, 10, 10, '.' }; // name, fatigue, life, arrow
		pq.push(entios['A']);
		pq.push(entios['B']);
		pq.push(entios['C']);
		pq.push(entios['D']);
		pq.push(entios['E']);
		pq.push(entios['F']);
	}
	else
	{
		entios ['1'] = { '1', 0, 10, 10, '.' }; // name, fatigue, life, arrow
		entios ['2'] = { '2', 0, 10, 10, '.' }; // name, fatigue, life, arrow
		entios ['3'] = { '3', 0, 10, 10, '.' }; // name, fatigue, life, arrow
		entios ['4'] = { '4', 0, 10, 10, '.' }; // name, fatigue, life, arrow
		entios ['5'] = { '5', 0, 10, 10, '.' }; // name, fatigue, life, arrow
		entios ['6'] = { '6', 0, 10, 10, '.' }; // name, fatigue, life, arrow
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
	//comprova que estigui viu
	while (entios[pq.top().name].life <= 0)
	{
		actions++;
		switchEntio();
	}

	//obtenir la x i la y del entio
	x = map->getX(pq.top().name);
	y = map->getY(pq.top().name);
	
	
	switch (button)
	{
	case enti::InputKey::A: case enti::InputKey::a:
		if (map->getCharMatrix(x,y - 1) == ':' || map->getCharMatrix(x, y - 1) == '.')
		{
			//coloca en el stack la posició inicial del entio
			if (entios[pq.top().name].movement.size() == 0)
			{
				entios[pq.top().name].movement.push({ x, y });
			}

			map->modifyMap(x, y, entios[pq.top().name].lastElement); //coloca el element que hi havia anteriorment en el terreny
			entios[pq.top().name].lastElement = map->getCharMatrix(x, y - 1); //agafa el element que hi ha en la posició on es mourà
			y--;
			addFatigue(pq.top().name, 1); // Afegir 1 de fatiga
			actions--;
			map->modifyMap(x, y, pq.top().name);//coloca el entio en la posició on s'ha mogut
			canUndo = true;
			entios[pq.top().name].movement.push({ x, y });//guarda el moviment al stack
		}
		break;
	case enti::InputKey::D: case enti::InputKey::d:
		if (map->getCharMatrix(x, y + 1) == ':' || map->getCharMatrix(x, y + 1) == '.')
		{
			if (entios[pq.top().name].movement.size() == 0)
			{
				entios[pq.top().name].movement.push({ x, y });
			}

			map->modifyMap(x, y, entios[pq.top().name].lastElement); //Modificar segons . o :
			entios[pq.top().name].lastElement = map->getCharMatrix(x, y + 1);
			y++;
			addFatigue(pq.top().name, 1); // Afegir 1 de fatiga
			actions--;
			map->modifyMap(x, y, pq.top().name);
			canUndo = true;
			entios[pq.top().name].movement.push({ x, y });
		}
		break;
	case enti::InputKey::S: case enti::InputKey::s:
		if (map->getCharMatrix(x + 1, y) == ':' || map->getCharMatrix(x + 1, y) == '.')
		{
			if (entios[pq.top().name].movement.size() == 0)
			{
				entios[pq.top().name].movement.push({ x, y });
			}

			map->modifyMap(x, y, entios[pq.top().name].lastElement); //Modificar segons . o :
			entios[pq.top().name].lastElement = map->getCharMatrix(x + 1, y);
			x++;
			addFatigue(pq.top().name, 1); // Afegir 1 de fatiga
			actions--;
			map->modifyMap(x, y, pq.top().name);
			canUndo = true;
			entios[pq.top().name].movement.push({ x, y });
		}
		break;
	case enti::InputKey::W: case enti::InputKey::w:
		if (map->getCharMatrix(x - 1, y) == ':' || map->getCharMatrix(x - 1, y) == '.')
		{
			if (entios[pq.top().name].movement.size() == 0)
			{
				entios[pq.top().name].movement.push({ x, y });
			}

			map->modifyMap(x, y, entios[pq.top().name].lastElement); //Modificar segons . o :
			entios[pq.top().name].lastElement = map->getCharMatrix(x - 1, y);
			x--;
			addFatigue(pq.top().name, 1); // Afegir 1 de fatiga
			actions--;
			map->modifyMap(x, y, pq.top().name);
			canUndo = true;
			entios[pq.top().name].movement.push({ x, y });
		}
		break;
	case enti::InputKey::Z: case enti::InputKey::z:
		
		undoMove(entios[pq.top().name].movement, entios[pq.top().name].lastElement, canUndo);
		break;
	}

	colorControl(x, y);

};


void Player::playerAttackSword(enti::InputKey button, bool turn1, Player &enemie)
{
	while (entios[pq.top().name].life <= 0)
	{
		actions++;
		switchEntio();
	}
	x = map->getX(pq.top().name);
	y = map->getY(pq.top().name);
	switch (button)
	{
	case enti::InputKey::NUM1: // UP
	{
		if (map->getCharMatrix(x - 1, y) == (turn1 ? '1' : 'A') || map->getCharMatrix(x - 1, y) == (turn1 ? '2' : 'B') || map->getCharMatrix(x - 1, y) == (turn1 ? '3' : 'C') ||
			map->getCharMatrix(x - 1, y) == (turn1 ? '4' : 'D') || map->getCharMatrix(x - 1, y) == (turn1 ? '5' : 'E') || map->getCharMatrix(x - 1, y) == (turn1 ? '6' : 'F'))
		{
			enemie.entioLoseLife(map->getCharMatrix(x - 1, y), 10);
		}
		else
		{
			std::cout << "You failed" << std::endl;
			_getch();
		}
		break;
	}
	case enti::InputKey::NUM2: //LEFT
	{
		if (map->getCharMatrix(x, y - 1) == (turn1 ? '1' : 'A') || map->getCharMatrix(x, y - 1) == (turn1 ? '2' : 'B') || map->getCharMatrix(x, y - 1) == (turn1 ? '3' : 'C') ||
			map->getCharMatrix(x, y - 1) == (turn1 ? '4' : 'D') || map->getCharMatrix(x, y - 1) == (turn1 ? '5' : 'E') || map->getCharMatrix(x, y - 1) == (turn1 ? '6' : 'F'))
		{
			enemie.entioLoseLife(map->getCharMatrix(x, y - 1), 10);
		}
		else
		{
			std::cout << "You failed" << std::endl;
			_getch();
		}
		break;
	}
	case enti::InputKey::NUM3: //DOWN
	{
		if (map->getCharMatrix(x + 1, y) == (turn1 ? '1' : 'A') || map->getCharMatrix(x + 1, y) == (turn1 ? '2' : 'B') || map->getCharMatrix(x + 1, y) == (turn1 ? '3' : 'C') ||
			map->getCharMatrix(x + 1, y) == (turn1 ? '4' : 'D') || map->getCharMatrix(x + 1, y) == (turn1 ? '5' : 'E') || map->getCharMatrix(x + 1, y) == (turn1 ? '6' : 'F'))
		{
			enemie.entioLoseLife(map->getCharMatrix(x + 1, y), 10);
		}
		else
		{
			std::cout << "You failed" << std::endl;
			_getch();
		}
		break;
	}
	case enti::InputKey::NUM4: //RIGHT
	{
		if (map->getCharMatrix(x, y + 1) == (turn1 ? '1' : 'A') || map->getCharMatrix(x, y + 1) == (turn1 ? '2' : 'B') || map->getCharMatrix(x, y + 1) == (turn1 ? '3' : 'C') ||
			map->getCharMatrix(x, y + 1) == (turn1 ? '4' : 'D') || map->getCharMatrix(x, y + 1) == (turn1 ? '5' : 'E') || map->getCharMatrix(x, y + 1) == (turn1 ? '6' : 'F'))
		{
			enemie.entioLoseLife(map->getCharMatrix(x, y + 1), 10);
		}
		else
		{
			std::cout << "You failed" << std::endl;
			_getch();
		}
		break;
	}
	};
	actions--;
}

void Player::playerAttackBow(enti::InputKey button, bool turn1, Player &enemie)
{
	while (entios[pq.top().name].life <= 0)
	{
		actions++;
		switchEntio();
	}
	x = map->getX(pq.top().name);
	y = map->getY(pq.top().name);
	bool hit = false;

	switch (button)
	{
	case enti::InputKey::NUM1: // UP
	{
		for (int i = 3; i < 11; i++)
		{
			if (map->getCharMatrix(x - i, y) == 'X')
			{
				break;
			}
			if (map->getCharMatrix(x - i, y) == (turn1 ? '1' : 'A') || map->getCharMatrix(x - i, y) == (turn1 ? '2' : 'B') || map->getCharMatrix(x - i, y) == (turn1 ? '3' : 'C') ||
				map->getCharMatrix(x - i, y) == (turn1 ? '4' : 'D') || map->getCharMatrix(x - i, y) == (turn1 ? '5' : 'E') || map->getCharMatrix(x - i, y) == (turn1 ? '6' : 'F'))
			{
				enemie.entioLoseLife(map->getCharMatrix(x - i, y), 11 - i); // 11 - i és el dmg segons la distancia
				hit = true;
				break;
			}
		}
		if (!hit)
		{
			std::cout << "You failed" << std::endl;
			_getch();
		}
		break;
	}
	case enti::InputKey::NUM2: //LEFT
	{
		for (int i = 3; i < 11; i++)
		{
			if (map->getCharMatrix(x, y - i) == 'X')
			{
				break;
			}
			if (map->getCharMatrix(x, y - i) == (turn1 ? '1' : 'A') || map->getCharMatrix(x, y - i) == (turn1 ? '2' : 'B') || map->getCharMatrix(x, y - i) == (turn1 ? '3' : 'C') ||
				map->getCharMatrix(x, y - i) == (turn1 ? '4' : 'D') || map->getCharMatrix(x, y - i) == (turn1 ? '5' : 'E') || map->getCharMatrix(x, y - i) == (turn1 ? '6' : 'F'))
			{
				enemie.entioLoseLife(map->getCharMatrix(x, y - i), 11 - i);
				hit = true;
				break;
			}
		}
		if (!hit)
		{
			std::cout << "You failed" << std::endl;
			_getch();
		}
		break;
	}
	case enti::InputKey::NUM3: //DOWN
	{
		for (int i = 3; i < 11; i++)
		{
			if (map->getCharMatrix(x + i, y) == 'X')
			{
				break;
			}
			if (map->getCharMatrix(x + i, y) == (turn1 ? '1' : 'A') || map->getCharMatrix(x + i, y) == (turn1 ? '2' : 'B') || map->getCharMatrix(x + i, y) == (turn1 ? '3' : 'C') ||
				map->getCharMatrix(x + i, y) == (turn1 ? '4' : 'D') || map->getCharMatrix(x + i, y) == (turn1 ? '5' : 'E') || map->getCharMatrix(x + i, y) == (turn1 ? '6' : 'F'))
			{
				enemie.entioLoseLife(map->getCharMatrix(x + i, y), 11 - i);
				hit = true;
				break;
			}
		}
		if (!hit)
		{
			std::cout << "You failed" << std::endl;
			_getch();
		}
		break;
	}
	case enti::InputKey::NUM4: //RIGHT
	{
		for (int i = 3; i < 11; i++)
		{
			if (map->getCharMatrix(x, y + i) == 'X')
			{
				break;
			}
			if (map->getCharMatrix(x, y + i) == (turn1 ? '1' : 'A') || map->getCharMatrix(x, y + i) == (turn1 ? '2' : 'B') || map->getCharMatrix(x, y + i) == (turn1 ? '3' : 'C') ||
				map->getCharMatrix(x, y + i) == (turn1 ? '4' : 'D') || map->getCharMatrix(x, y + i) == (turn1 ? '5' : 'E') || map->getCharMatrix(x, y + i) == (turn1 ? '6' : 'F'))
			{
				enemie.entioLoseLife(map->getCharMatrix(x, y + i), 11 - i);
				hit = true;
				break;
			}
		}
		if (!hit)
		{
			std::cout << "You failed" << std::endl;
			_getch();
		}
		break;
	}
	};
	actions--;
}


char Player::getEntio()
{
	while (entios[pq.top().name].life <= 0)
	{
		pq.pop();
	}
	return pq.top().name;
}

void Player::entioLoseLife(char name, int dmg)
{
	entios[name].life = entios[name].life - dmg;
	if (entios[name].life <= 0)
	{
		map->modifyMap(map->getX(name), map->getY(name), entios[name].lastElement);//coloca el element que hi havia anteriormen en la posició del player mort
		entiosAlive--;
	}
	std::cout << "Entio " << entios[name].name << " te " << entios[name].life << " vides" << std::endl;
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
	if (entios[name].life > 0)
	{
		addFatigue(name, 1);
		pq.push(entios[name]);
	}
}

void Player::addFatigue(char name, int numF)
{
	entios[name].fatigue += numF;
}

void Player::loseFatigue(char name, int numF)
{
	entios[name].fatigue -= numF;
}

void Player::colorControl(int x, int y)
{
	
}

void Player::undoMove(std::stack<std::pair<int, int>> movement, char &element, bool &canUndo)
{
	//Hem creat un stack per guardar els moviments per si es pot fer "Z" més d'un cop, però com que a les especificacions posa que només un moviment ho hem limit amb un boolean
	if (canUndo)
	{
		map->modifyMap(movement.top().first, movement.top().second, element);
		movement.pop();
		element = map->getCharMatrix(movement.top().first, movement.top().second);
		map->modifyMap(movement.top().first, movement.top().second, pq.top().name);
		loseFatigue(pq.top().name, 1);		
		actions++;
	}

	else
		std::cout << "You only can undo one movement" << std::endl;

	canUndo = false;
}

