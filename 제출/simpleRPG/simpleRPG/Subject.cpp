#include "Subject.h"




Subject::Subject()
{
}

void Subject::AddObserver(Observer* addObserver)
{
	m_Noticelist.push_back(addObserver);
}

void Subject::RemoveObserver(Observer* remove)
{
	vector<Observer*>::iterator iter = m_Noticelist.begin();

	while (*iter != remove)
		iter++;

	if (iter == m_Noticelist.end())
		return;

	m_Noticelist.erase(iter);
}


Subject::~Subject()
{
}
