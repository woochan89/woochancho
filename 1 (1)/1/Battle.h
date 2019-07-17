#pragma once
#include"Archer.h"
#include"Character.h"
#include"Magician.h"
#include"Warrior.h"
#include"Mecro.h"
#include"Draw.h"
class Battle
{
private:
	Draw DrawManager;
protected:
	Character *CharacterList[3];
public:
	void BattleInterface(int Floor);
	Battle();
	~Battle();
};

