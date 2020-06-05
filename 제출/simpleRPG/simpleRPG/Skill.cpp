#include "Skill.h"



Skill::Skill()
{
}


Skill::~Skill()
{
}




WarriorSkill::WarriorSkill()
{
	ObjectSkill *tmp = new ObjectSkill();
	tmp->Name = "십자베기";
	tmp->condition = NOMAL;
	tmp->Dmg = 1.5;
	tmp->GetLevel = 1;
	tmp->MpConsumtion = 3;
	tmp->Target = ONE_ENEMY;
	m_lSkill.push_back(tmp);
}

WarriorSkill::~WarriorSkill()
{

}
