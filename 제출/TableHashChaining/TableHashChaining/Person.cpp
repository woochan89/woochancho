#include "Person.h"
#include<string.h>

//������ ���
void PrintPerson(Person p)
{
	printf("%s\n", p.name);
	printf("%d\n", p.ssn);
	printf("%s\n\n", p.addr);
}

//������ �Է�
void InputPerson(Person &p, int ssn, const char name[], const char addr[])
{
	p.ssn = ssn;
	strcpy
}