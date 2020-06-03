#pragma once
#include"Mecro.h"
#include"Weapon.h"
#include"Observer.h"




class Player:public Observer
{
protected:
	ObjectStat *m_cPlayerStat;
	//Weapon* m_cWeapon;
	bool alarmState;
public:
	virtual void notify (string boss_name);
	void AlarmControl(bool flag) { alarmState = flag; }

	Player(ObjectStat *stat);
	~Player();
};