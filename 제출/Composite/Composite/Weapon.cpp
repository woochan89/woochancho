#include "Weapon.h"



Weapon::Weapon(string name, int atk, int Int) :Item(name)
{
	m_iATK = atk;
	m_iInt = Int;
}

int Weapon::View()
{
	//cout << setiosflags(ios::right) << setw(GetSize());
	//cout << setfill(' ') << GetName().c_str() << " - Item" << endl;]

	cout << GetName() << " ���ݷ� : " << m_iATK << " �ֹ��� : " << m_iInt << endl;
	return 1;

}


Weapon::~Weapon()
{
}
