#include "Magician.h"



Magician::Magician()
{
	int ClassStat;
	Class = RandClass();
	if (Class == 1)
		ClassStat = 5;
	else if (Class == 2)
		ClassStat = 4;
	else if (Class == 3)
		ClassStat = 3;
	else if (Class == 4)
		ClassStat = 2;
	else
		ClassStat = 1;
	Name = "마법사";
	Lv = 1;
	Atk = 1 + ClassStat;
	Def = 1 + ClassStat;
	Range = 3;
	MaxHp = 10 + ClassStat;
	CurHp = MaxHp;
}

void Magician::ShowCharacter()
{
	cout << Name << "   " << Class << " 등급";
}


Magician::~Magician()
{
}
