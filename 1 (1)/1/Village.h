#pragma once
#include"Archer.h"
#include"Character.h"
#include"Magician.h"
#include"Warrior.h"
#include"Draw.h"
#include"Dungeon.h"
class Village
{
private:
	int m_iDay;
	int m_iMoney;
	bool m_bFacilityFlag;
	Draw DrawManager;
	Dungeon DungeonManager;
	static Character *CharacterList[3];
	Character *tmp[5];
public:
	void GameStart();
	void Menu();
	void AssemblyFacility();
	void ShowStatus();
	Village();
	~Village();
};

