#include "Weapon.h"



Weapon::Weapon(string name, string stat) :Inventory(name, stat)
{

}

void Weapon::View()
{
	cout << setiosflags(ios::right) << setw(GetSize());
	cout << setfill(' ') << GetName().c_str() << " - Item" << endl;
}


Weapon::~Weapon()
{
}
