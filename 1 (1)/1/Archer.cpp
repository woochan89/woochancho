#include "Archer.h"



Archer::Archer()
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
	Name = "±Ã¼ö";
	Lv = 1;
	Atk=1+ClassStat;
	Def= 1 + ClassStat;
	Range = 3;
	MaxHp = 10 + ClassStat;
	CurHp=MaxHp;
}

void Archer::ShowCharacter()
{
	cout<< Name<<"   "<<Class << " µî±Þ";
}


Archer::~Archer()
{
}
