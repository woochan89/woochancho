#pragma once
#include"Mecro.h"
#include"Player.h"
#include"Skill.h"


class AbstractFactory
{
public:
	virtual ObjectStat* makePlayer(string name) = 0;
	virtual list<Skill*> makeSkill() = 0;
	AbstractFactory();
	~AbstractFactory();
};

class WarriorCharacter :public AbstractFactory
{
public:
	virtual ObjectStat* makePlayer(string name);
	virtual list<Skill*> makeSkill();

};

class RogueCharacter :public AbstractFactory
{
public:
	virtual ObjectStat* makePlayer(string name);
	virtual list<Skill*> makeSkill();

};
class HunterCharacter :public AbstractFactory
{
public:
	virtual ObjectStat* makePlayer(string name);
	virtual list<Skill*> makeSkill();

};
class PriestCharacter :public AbstractFactory
{
public:
	virtual ObjectStat* makePlayer(string name);
	virtual list<Skill*> makeSkill();

};
class MagicianCharacter :public AbstractFactory
{
public:
	virtual ObjectStat* makePlayer(string name);
	virtual list<Skill*> makeSkill();

};
