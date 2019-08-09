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
	int *m_iMoney;
	int *m_iDay;
public:
	bool Menu(Character *CharacterList[]);
	void Battle(int Floor, Character *CharacterList[],int Stage=1);
	int NextFloorChoice();
	void ShowStatus(Character *CharacterList[]);
	Dungeon(int *Money, int *Day);
	~Dungeon();
};

