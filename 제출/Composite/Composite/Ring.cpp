#include "Ring.h"



Ring::Ring(string name,int Int):Item(name,RING)
{
	m_iInt = Int;
}

int Ring::View()
{
	cout << setw(Getlevel() + 2) << setfill(' ') << '-';
	cout << GetName() << " �ֹ��� : " << m_iInt << endl;
	return 1;

}


Ring::~Ring()
{
}
