#pragma once
#include<string>
using namespace std;


class Inventory
{
	Inventory *parent;
	const string m_sName;
	const string m_sStat;
public:
	virtual void View()=0;
	virtual void AddInventory(Inventory* inventory) = 0;
	virtual void RemoveInventory(Inventory* inventory) = 0;
	void SetParent(Inventory* _parent);
	Inventory* GetParent();
	string GetName();
	int Getlevel();
	Inventory(string name,string stat);
	~Inventory();
protected:
	int GetSize();
};

