#pragma once
#include"Mecro.h"
#include"Player.h"
class BossAlarm
{
	string name;
	vector<Player*> noticelist;
public:
	virtual void notice()=0;
	void addObserver();
};

class Monster:public BossAlarm
{
public:
	virtual void notice();
	Monster();
	~Monster();
};

