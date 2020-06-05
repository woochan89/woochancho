#include "Subject.h"




Subject::Subject():m_eCondition(NOMAL)
{
}

void Subject::AddObserver(Observer* addObserver)
{
	m_vNoticelist.push_back(addObserver);
}

void Subject::RemoveObserver(Observer* remove)
{
	vector<Observer*>::iterator iter = m_vNoticelist.begin();

	while (*iter != remove)
		iter++;

	if (iter == m_vNoticelist.end())
		return;

	m_vNoticelist.erase(iter);
}

void Subject::Notification()
{
	vector<Observer*>::iterator iter = m_vNoticelist.begin();
	
	while (m_eCondition != NOMAL && iter!= m_vNoticelist.end())
	{
		(*iter)->notify(m_cMonster->Name,m_eCondition);
		iter++;
	}

}

void Subject::Notification(Observer* target)
{
	if (m_eCondition != NOMAL)
	{
		target->notify(m_cMonster->Name, m_eCondition);
	}
}


Subject::~Subject()
{
}
