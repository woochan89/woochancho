#include "Person.h"
#include<string.h>

//데이터 출력
void PrintPerson(Person p)
{
	printf("%s\n", p.name);
	printf("%d\n", p.ssn);
	printf("%s\n\n", p.addr);
}

//데이터 입력
void InputPerson(Person &p, int ssn, const char name[], const char addr[])
{
	p.ssn = ssn;
	strcpy
}