#pragma once
#include"Mecro.h"
#include"Player.h"



class Subject
{
private:
	vector<Observer*> m_vNoticelist;
protected:
	ObjectStat* m_cMonster;
	bool isAppear;
public:
	void AddObserver(Observer* add);
	void RemoveObserver(Observer* remove);
	void Notification();
	void Notification(Observer* target);
	Subject();
	~Subject();

};

