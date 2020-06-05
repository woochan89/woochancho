#include "Abstract_Factory.h"



Abstract_Factory::Abstract_Factory()
{
}


Abstract_Factory::~Abstract_Factory()
{
}





Player* WarriorCharacter :: makePlayer(string name)
{
	Player* tmp = new Warrior(name);
	return tmp;
}

Skill* WarriorCharacter:: makeSkill()
{
	Skill* tmp = new WarriorSkill();
	return tmp;
}
