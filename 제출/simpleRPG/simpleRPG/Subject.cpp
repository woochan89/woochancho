#include "Subject.h"




Subject::Subject():isAppear(false)
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
	
	while (isAppear == true && iter!= m_vNoticelist.end())
	{
		(*iter)->notify(m_cMonster->Name);
		iter++;
	}

}

void Subject::Notification(Observer* target)
{
	if (isAppear == true)
	{
		target->notify(m_cMonster->Name);
	}
}


Subject::~Subject()
{
}
