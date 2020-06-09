#pragma once
#include"Mecro.h"
#include"Subject.h"



class Monster:public Subject
{

public:
	ObjectStat* m_Monster;
	Condition m_Condition;
	Skill* m_Skill;
	const int m_skillpercent;
	int m_Exp;

	virtual void Notification()
	{
		vector<Observer*>::iterator iter = m_Noticelist.begin();
		while (m_Condition != NOMAL && iter != m_Noticelist.end())
		{
			(*iter)->notify(m_Monster->Name, m_Condition);
			iter++;
		}
	}

	virtual void Notification(Observer* target)
	{
		if (m_Condition != NOMAL)
			target->notify(m_Monster->Name, m_Condition);
	}

	Monster(ObjectStat* stat,int skillpercent):m_skillpercent(skillpercent),  m_Condition(NOMAL)
	{ 
		m_Monster = stat;
		m_Monster->MaxHp = m_Monster->Hp;
		m_Monster->MaxMp = m_Monster->Mp;
		m_Exp = m_Monster->Lv*1.2;
	}
	~Monster() {}
};

