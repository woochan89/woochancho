#include "Armor.h"



Armor::Armor(string name,int def):Item(name)
{
	m_iDef = def;
}

int Armor::View()
{
	cout << GetName() << " ���� : " << m_iDef  << endl;
	return 1;

}


Armor::~Armor()
{
}
