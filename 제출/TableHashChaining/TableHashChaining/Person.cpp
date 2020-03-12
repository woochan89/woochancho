#include "Person.h"
#include<string.h>
#include<stdlib.h>

//데이터 출력
void PrintPerson(Person p)
{
	printf("주민등록번호 : %s\n", p.name);
	printf("이름 : %d\n", p.ssn);
	printf("주소 : %s\n\n", p.addr);
}

//데이터 입력
Person* InputPerson(int ssn, const char name[], const char addr[])
{
	Person * newP = (Person*)malloc(sizeof(Person));

	newP->ssn = ssn;
	strcpy(newP->name, name);
	strcpy(newP->addr, addr);
	return newP;
}