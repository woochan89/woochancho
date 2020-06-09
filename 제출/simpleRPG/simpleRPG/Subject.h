#pragma once
#include"Mecro.h"
#include"Player.h"



class Subject
{
protected:

	vector<Observer*> m_Noticelist;
protected:
public:
	void AddObserver(Observer* add);
	void RemoveObserver(Observer* remove);
	virtual void Notification()=0;
	virtual void Notification(Observer* target)=0;
	Subject();
	~Subject();

};

