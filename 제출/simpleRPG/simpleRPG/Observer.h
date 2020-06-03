#pragma once
#include"Mecro.h"
#include"Player.h"


class Observer
{
public:
	virtual void notify(string boss_name) = 0;

	Observer() {}
	~Observer() {}
};

