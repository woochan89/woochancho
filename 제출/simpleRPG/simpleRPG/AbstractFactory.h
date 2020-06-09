#pragma once
#include"Mecro.h"
#include"Player.h"
#include"Skill.h"


class AbstractFactory
{
public:
	virtual ObjectStat* makePlayer(string name) = 0;
	virtual Skill* makeSkill() = 0;
	AbstractFactory();
	~AbstractFactory();
};

class WarriorCharacter :public AbstractFactory
{
public:
	virtual ObjectStat* makePlayer(string name);
	virtual Skill* makeSkill();

};
