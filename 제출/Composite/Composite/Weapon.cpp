#include "Weapon.h"



Weapon::Weapon(string name, int atk, int def) :Inventory(name, atk,def)
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
