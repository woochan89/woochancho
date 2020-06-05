#pragma once
#include"Mecro.h"
#include"Player.h"
#include"Skill.h"
class Abstract_Factory
{
public:
	virtual Player* makePlayer(string name) = 0;
	virtual Skill* makeSkill() = 0;
	Abstract_Factory();
	~Abstract_Factory();
};

class WarriorCharacter :public Abstract_Factory
{
public:
	virtual Player* makePlayer(string name);
	virtual Skill* makeSkill();

};


class RogueCharacter :public Abstract_Factory
{
public:
	virtual Player makePlayer(string name);
	virtual Skill makeSkill();

};


class HunterCharacter :public Abstract_Factory
{
public:
	virtual Player makePlayer(string name);
	virtual Skill makeSkill();

};


class PreistCharacter :public Abstract_Factory
{
public:
	virtual Player makePlayer(string name);
	virtual Skill makeSkill();

};


class MagicianCharacter :public Abstract_Factory
{
public:
	virtual Player makePlayer(string name);
	virtual Skill makeSkill();

};

