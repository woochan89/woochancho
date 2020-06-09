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
	Skill();
	~Skill();
};

class WarriorSkill :public Skill
{
public:
	WarriorSkill();
	~WarriorSkill();
};

class RogueSkill :public Skill
{

};

class HunterSkill :public Skill
{

};

class PriestSkill :public Skill
{

};

class MagicianSkill :public Skill
{

};


class MonsterSkill :public Skill
{
public:
	MonsterSkill(string name, Condition condition, float dmg, int getlv, int mpconsume, int target);
	~MonsterSkill();

};

