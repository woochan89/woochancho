#pragma once
#include"Mecro.h"
#include"Singleton.h"

class Draw:public Singleton<Draw>
{
private:

public:
	void showStat(ObjectStat* stat);
	void showSkill(ObjectSkill* skill);
	void showEquipment();

	Draw();
	~Draw();
};

