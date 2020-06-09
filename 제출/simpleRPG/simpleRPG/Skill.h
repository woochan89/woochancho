#pragma once
#include"Mecro.h"



class Skill
{
protected:
	ObjectSkill* m_Skill;
public:
	ObjectSkill* GetSkill() 
	{
		return m_Skill;
	}
};

class WarriorSkill :public Skill
{
public:
	WarriorSkill();
};

class RogueSkill :public Skill
{
	RogueSkill(string name, Condition condition, float dmg, int getlv, int mpconsume, int target);
};

class HunterSkill :public Skill
{
	HunterSkill(string name, Condition condition, float dmg, int getlv, int mpconsume, int target);
};

class PriestSkill :public Skill
{
	PriestSkill(string name, Condition condition, float dmg, int getlv, int mpconsume, int target);
};

class MagicianSkill :public Skill
{
	MagicianSkill(string name, Condition condition, float dmg, int getlv, int mpconsume, int target);
};


class MonsterSkill :public Skill
{
public:
	MonsterSkill(string name, Condition condition, float dmg, int getlv, int mpconsume, int target);
	~MonsterSkill();

};

