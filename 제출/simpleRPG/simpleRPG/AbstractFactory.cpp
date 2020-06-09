#include "AbstractFactory.h"



AbstractFactory::AbstractFactory()
{
}


AbstractFactory::~AbstractFactory()
{
}





ObjectStat* WarriorCharacter :: makePlayer(string name)
{
	ObjectStat* tmp = new ObjectStat();
	tmp->Name = name;
	tmp->Atk = 5;
	tmp->Def = 1;
	tmp->MaxHp = 30;
	tmp->Hp = 30;
	tmp->MaxMp = 10;
	tmp->Mp = 10;
	tmp->Lv = 1;

	return tmp;
}

Skill* WarriorCharacter:: makeSkill()
{
	Skill* tmp = new WarriorSkill();
	return tmp;
}
