#include "Weapon.h"



Weapon::Weapon(string name, int atk, int Int) :Item(name,WEAPON)
{
	m_iATK = atk;
	m_iInt = Int;
}

int Weapon::View()
{
	cout << setw(Getlevel()+2) << setfill(' ') << '-';
	cout << GetName() << " 공격력 : " << m_iATK << " 주문력 : " << m_iInt << endl;
	return 1;
}


Weapon::~Weapon()
{
}
