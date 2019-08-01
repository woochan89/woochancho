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
	Dungeon *DungeonManager;
	Character *CharacterList[3];
	Character *tmp[5];
public:
	void MainMenu();
	void GameStart();
	void VillageInterface();
	void ShowStatus();
	void HireCharacter();
	void AssemblyFacility(bool Check);
	void AdjustCharacter();
	void Save();
	void Load(bool check=false);
	void DeleteAll();
	Village();
	~Village();
};