#pragma once
#include"AbstractFactory.h"
#include"Mecro.h"
#include"Observer.h"
#include"Skill.h"
#include"Item.h"




class Player:public Observer
{
public:

	ObjectStat *m_PlayerStat;
	vector<Skill*> m_Skill;
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
	Warrior();
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
