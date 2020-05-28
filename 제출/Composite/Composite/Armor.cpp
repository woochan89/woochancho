#include "Armor.h"



Armor::Armor(string name,int def):Item(name,ARMOR)
{
	m_iDef = def;
}

int Armor::View()
{
	cout << setw(Getlevel()) << setfill(' ') << '-';
	cout << GetName() << " ¹æ¾î·Â : " << m_iDef  << endl;
	return 1;

}


Armor::~Armor()
{
}
