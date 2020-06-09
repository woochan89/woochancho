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

list<Skill*> WarriorCharacter:: makeSkill()
{
	Skill* tmp = new WarriorSkill();
	return tmp;
}

ObjectStat* RogueCharacter::makePlayer(string name)
{
	ObjectStat* tmp = new ObjectStat();
	tmp->Name = name;
	tmp->Atk = 7;
	tmp->Def = 1;
	tmp->MaxHp = 20;
	tmp->Hp = 20;
	tmp->MaxMp = 10;
	tmp->Mp = 10;
	tmp->Lv = 1;

	return tmp;
}

list<Skill*> RogueCharacter::makeSkill()
{
	Skill* tmp = new WarriorSkill();
	return tmp;
}

ObjectStat* HunterCharacter::makePlayer(string name)
{
	ObjectStat* tmp = new ObjectStat();
	tmp->Name = name;
	tmp->Atk = 7;
	tmp->Def = 1;
	tmp->MaxHp = 20;
	tmp->Hp = 20;
	tmp->MaxMp = 8;
	tmp->Mp = 8;
	tmp->Lv = 1;

	return tmp;
}

list<Skill*> HunterCharacter::makeSkill()
{
	Skill* tmp = new WarriorSkill();
	return tmp;
}

ObjectStat* PriestCharacter::makePlayer(string name)
{
	ObjectStat* tmp = new ObjectStat();
	tmp->Name = name;
	tmp->Atk = 3;
	tmp->Def = 1;
	tmp->MaxHp = 20;
	tmp->Hp = 20;
	tmp->MaxMp = 15;
	tmp->Mp = 15;
	tmp->Lv = 1;

	return tmp;
}

list<Skill*> PriestCharacter::makeSkill()
{
	Skill* tmp = new WarriorSkill();
	return tmp;
}

ObjectStat* MagicianCharacter::makePlayer(string name)
{
	ObjectStat* tmp = new ObjectStat();
	tmp->Name = name;
	tmp->Atk = 2;
	tmp->Def = 1;
	tmp->MaxHp = 18;
	tmp->Hp = 18;
	tmp->MaxMp = 20;
	tmp->Mp = 20;
	tmp->Lv = 1;

	return tmp;
}

list<Skill*> MagicianCharacter::makeSkill()
{
	Skill* tmp = new WarriorSkill();
	return tmp;
}
