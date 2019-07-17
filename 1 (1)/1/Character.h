#pragma once
#include"Mecro.h"

class Character
{
protected:
	string Name;
	int Class;
	int Lv;
	int Atk;
	int Def;
	int Range;
	int MaxHp;
	int CurHp;
public:
	Character();
	virtual void ShowCharacter()=0;
	void InputData(int Number, Character *Char);
	int RandClass();
	virtual ~Character();
};