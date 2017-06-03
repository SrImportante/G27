#include "Player.hh"
#include "Map.hh"
#include <iostream>
#include <queue>
#include <vector>
#include <map>

Player::Player(Map *map2, int numPlayer)
{
	map = map2;
	action = 10;
	numEntios = 6;
	//std::priority_queue<Entio, std::vector<Entio>, Entio> pq;
	if (numPlayer = 1)
	{
		entios["A"] = { 'A', 0, 10, 10 };
		entios["B"] = { 'B', 0, 10, 10 };
		entios["C"] = { 'C', 0, 10, 10 };
		entios["D"] = { 'D', 0, 10, 10 };
		entios["E"] = { 'E', 0, 10, 10 };
		entios["F"] = { 'F', 0, 10, 10 };
		pq.push(entios["A"]);
		pq.push(entios["B"]);
		pq.push(entios["C"]);
		pq.push(entios["D"]);
		pq.push(entios["E"]);
		pq.push(entios["F"]);
	}
	else
	{
		entios["1"] = { '1', 0, 10, 10 };
		entios["2"] = { '2', 0, 10, 10 };
		entios["3"] = { '3', 0, 10, 10 };
		entios["4"] = { '4', 0, 10, 10 };
		entios["5"] = { '5', 0, 10, 10 };
		entios["6"] = { '6', 0, 10, 10 };
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

	switch (button)
	{
	case enti::InputKey::A:
		if (map->getCharMatrix(x, y - 1) != 'X' && map->getCharMatrix(x, y - 1) != 'O' && map->getCharMatrix(x, y - 1) != 'A' && map->getCharMatrix(x, y - 1) != 'B'
			&& map->getCharMatrix(x, y - 1) != 'C' && map->getCharMatrix(x, y - 1) != 'D' && map->getCharMatrix(x, y - 1) != 'E' && map->getCharMatrix(x, y - 1) != 'F'
			&& map->getCharMatrix(x, y - 1) != '1' && map->getCharMatrix(x, y - 1) != '2' && map->getCharMatrix(x, y - 1) != '2' && map->getCharMatrix(x, y - 1) != '3'
			&& map->getCharMatrix(x, y - 1) != '4' && map->getCharMatrix(x, y - 1) != '5' && map->getCharMatrix(x, y - 1) != '6')
		{
			map->modifyMap(x, y, '.');
			y--;
		}
		map->modifyMap(x, y, pq.top().name);
		//addFatigue(pq.top().name, 1); // Afegir 1 de fatiga
	}
};

bool Player::allDead()
{
	return numEntios = 0;
};

void Player::addFatigue(char name, int numF)
{
	switch (name)
	{
	case 'A':
		entios["A"].fatigue += numF;
		pq.pop();
		pq.push(entios["A"]);
		break;
	case 'B':
		entios["B"].fatigue += numF;
		pq.pop();
		pq.push(entios["B"]);
		break;
	case 'C':
		entios["C"].fatigue += numF;
		pq.pop();
		pq.push(entios["C"]);
		break;
	case 'D':
		entios["D"].fatigue += numF;
		pq.pop();
		pq.push(entios["D"]);
		break;
	case 'E':
		entios["E"].fatigue += numF;
		pq.pop();
		pq.push(entios["E"]);
		break;
	case 'F':
		entios["F"].fatigue += numF;
		pq.pop();
		pq.push(entios["F"]);
		break;
	case '1':
		entios["1"].fatigue += numF;
		pq.pop();
		pq.push(entios["1"]);
		break;
	case '2':
		entios["2"].fatigue += numF;
		pq.pop();
		pq.push(entios["2"]);
		break;
	case '3':
		entios["3"].fatigue += numF;
		pq.pop();
		pq.push(entios["3"]);
		break;
	case '4':
		entios["4"].fatigue += numF;
		pq.pop();
		pq.push(entios["4"]);
		break;
	case '5':
		entios["4"].fatigue += numF;
		pq.pop();
		pq.push(entios["4"]);
		break;
	case '6':
		entios["4"].fatigue += numF;
		pq.pop();
		pq.push(entios["4"]);
		break;
	}
}