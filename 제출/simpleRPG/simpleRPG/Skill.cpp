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
	m_Skill=tmp;
}

WarriorSkill::~WarriorSkill()
{

}


MonsterSkill::MonsterSkill(string name, Condition condition, float dmg, int getlv, int mpconsume, int target)
{
	ObjectSkill *tmp = new ObjectSkill();
	tmp->Name = name;
	tmp->condition = condition;
	tmp->Dmg = dmg;
	tmp->GetLevel = 1;
	tmp->MpConsumtion = 2;
	tmp->Target = ONE_ENEMY;
	m_Skill = tmp;
}

MonsterSkill::~MonsterSkill()
{

}
