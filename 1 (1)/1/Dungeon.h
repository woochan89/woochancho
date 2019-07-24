#pragma once
#include"Mecro.h"
#include"Draw.h"
#include"Archer.h"
#include"Character.h"
#include"Magician.h"
#include"Warrior.h"
#include"Monster.h"


class Dungeon
{
private:
	Draw DrawManager;
	Character *MonsterList[3];
public:
	bool Menu(Character *CharacterList[], int *Money);
	void Battle(int Floor, Character *CharacterList[],int Stage=1);
	bool NextFloorChoice();
	Dungeon();
	~Dungeon();
};

