#pragma once
#include"Mecro.h"
#include"Draw.h"
#include"Battle.h"
class Dungeon:Battle
{
private:
	Draw DrawManager;
public:
	void Menu();
	Dungeon();
	~Dungeon();
};

