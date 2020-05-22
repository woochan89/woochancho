#pragma once
#include"Singleton.h"
#include<list>
#include<string>
using namespace std;

class Gamemanager
{
	list<int> m_sTower;
public:

	void stacktower(int num);
	void removetower(int num);

	Gamemanager();
	~Gamemanager();
};

