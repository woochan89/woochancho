#pragma once
#include"AbstractFactory.h"
#include"Mecro.h"
#include"Observer.h"
#include"Skill.h"
#include"Item.h"
#include<deque>




class Player:public Observer
{
public:

	ObjectStat *m_PlayerStat;
	vector<Skill*> m_Skill;
	deque<Skill*> m_TmpSkill;
	Condition m_Condition;
	Item* m_Weapon;
	Item* m_Armor;
	Item* m_Accessory;
	list<Item*> m_Inventory;
	int m_Exp;


	virtual void notify (string boss_name, Condition condition);
	virtual void LVup() = 0;
	string ReturnCondition(Condition condition);
	void GetExp(int exp);
	Player();
	virtual ~Player();
};


class Warrior :public Player
{

public:
	virtual void LVup();
};

class Rogue :public Player
{
public:
	virtual void LVup();

};

class Hunter :public Player
{
public:
	virtual void LVup();

};

class Priest :public Player
{
public:
	virtual void LVup();

};

class Magician :public Player
{
public:
	virtual void LVup();

};
