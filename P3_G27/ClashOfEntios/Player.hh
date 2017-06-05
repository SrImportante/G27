#pragma once
#include "Map.hh"
#include "Input.inl.hh"
#include <queue>
#include <map>
#include <string>
#include "Renderer.hh"

struct Entio
{
	char name;
	int fatigue;
	int life;
	int arrow;
	bool operator()(const Entio &a,const Entio &b) //poder comparar fatigues
	{
		if (a.fatigue > b.fatigue) return true; return false;
	};
};

class Player
{
private:
	Map *map;
	int x, y, actions, entiosAlive;
	std::priority_queue<Entio, std::vector<Entio>, Entio> pq;
	//std::map<std::string, Entio> entios;
	std::map<char, Entio> entios;
	char lastElement;
public:
	Player(Map *map2, int numPlayer);
	void movePlayer(enti::InputKey button);
	void playerAttackSword(enti::InputKey button, bool turn1, Player &enemie);
	void playerAttackBow(enti::InputKey button, bool turn1, Player &enemie);
	bool allDead();
	void addFatigue(char name, int numF);
	int getActions();
	void setActions(int num);
	void switchEntio();
	void colorControl();
	void entioLoseLife(char name, int dmg);
	char getEntio();
};