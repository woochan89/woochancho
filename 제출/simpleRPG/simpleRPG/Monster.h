#pragma once
#include"Mecro.h"
#include"Subject.h"



class Monster:public Subject
{

public:
	void SpawnBoss()
	{ isAppear = true; }
	Monster(ObjectStat* stat) { m_cMonster = stat; }
	~Monster() {}
};

