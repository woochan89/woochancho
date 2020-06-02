#pragma once
#include"Mecro.h"
#include"Monster.h"
#include"Weapon.h"

class Obserber
{
public:
	virtual void notify(string boss_name) = 0;
};

class Player:public Obserber
{
protected:
	PlayerStat* m_cPlayer;
	Weapon* m_cWeapon;
public:
	virtual void notify(string boss_name);

	Player();
	~Player();
};