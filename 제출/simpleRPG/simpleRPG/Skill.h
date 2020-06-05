#pragma once
#include"Mecro.h"



class Skill
{
protected:
	list<ObjectSkill*> m_lSkill;
public:
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
