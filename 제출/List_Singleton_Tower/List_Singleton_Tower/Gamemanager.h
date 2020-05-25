#pragma once
#include"Singleton.h"
#include"Drawmanager.h"
#define TOWER_MAX 10

class Gamemanager:public Singleton<Gamemanager>
{
	list<int> m_sTower;
	Drawmanager Draw;
public:

	void stacktower();
	void removetower();

	Gamemanager();
	~Gamemanager();
};

