#pragma once
#include "Map.hh"
#include "Input.inl.hh"
#include <queue>
#include <map>
#include <string>
#include <stack>
#include "Renderer.hh"


struct Entio
{
	char name;
	int fatigue;
	int life;
	int arrow;
	char lastElement;
	std::stack<std::pair<int, int>> movement;
	bool operator()(const Entio &a,const Entio &b) //poder comparar fatigues
	{
		if (a.fatigue > b.fatigue) return true; return false;
	};
};



class Player
{
private:
	Map *map;
	int x, y, x2, y2, actions, entiosAlive;
	bool canUndo;
	std::priority_queue<Entio, std::vector<Entio>, Entio> pq;
	//std::map<std::string, Entio> entios;
	std::map<char, Entio> entios;
	
	
public:
	Player(Map *map2, int numPlayer);
	void movePlayer(enti::InputKey button);
	void playerAttackSword(enti::InputKey button, bool turn1, Player &enemie);
	void playerAttackBow(enti::InputKey button, bool turn1, Player &enemie);
	bool allDead();
	void addFatigue(char name, int numF);
	void loseFatigue(char name, int numF);
	int getActions();
	void setActions(int num);
	void switchEntio();
	void colorControl(int x, int y);
	void entioLoseLife(char name, int dmg);
	char getEntio();
	void undoMove(std::stack<std::pair<int, int>> movement, char &element, bool &canUndo);
	void killEntio(Player &enemie,int x, int y);
	bool isAnyoneAlive();
};