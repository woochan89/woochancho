#pragma once
#include"Mecro.h"
#include"Weapon.h"
#include"Observer.h"
#include"Skill.h"




class Player:public Observer
{
protected:
	ObjectStat *m_cPlayerStat;
	//Weapon* m_cWeapon;
	list<Skill*> m_cSkill;
public:
	virtual void notify (string boss_name, Condition condition);
	string ReturnCondition(Condition condition);
	Player(string name);
	virtual ~Player();
};


class Warrior :public Player
{
public:
	Warrior(string name);
	~Warrior();
};

class Rogue :public Player
{

};

class Hunter :public Player
{

};

class Priest :public Player
{

};

class Magician :public Player
{

};
