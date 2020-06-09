#include "Skill.h"


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

RogueSkill::RogueSkill(string name, Condition condition, float dmg, int getlv, int mpconsume, int target)
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

HunterSkill::HunterSkill(string name, Condition condition, float dmg, int getlv, int mpconsume, int target)
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

PriestSkill::PriestSkill(string name, Condition condition, float dmg, int getlv, int mpconsume, int target)
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

MagicianSkill::MagicianSkill(string name, Condition condition, float dmg, int getlv, int mpconsume, int target)
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
