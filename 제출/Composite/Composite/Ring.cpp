#include "Ring.h"



Ring::Ring(string name,int Int):Item(name)
{
	m_iInt = Int;
}

int Ring::View()
{
	cout << setw(Getlevel()) << setfill(' ') << '-';

	return 1;

}


Ring::~Ring()
{
}
