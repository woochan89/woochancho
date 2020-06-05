#pragma once
#include"Mecro.h"
#include"Player.h"


class Observer
{
public:
	virtual void notify(string boss_name, Condition condition) = 0;

	Observer() {}
	~Observer() {}
};

