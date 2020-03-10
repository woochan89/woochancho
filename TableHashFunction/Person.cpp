#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Person.h"

int GetSSN(Person* p)
{
	return p->ssn;;
}

void ShowPerInfo(Person* p)
{
	if (p == NULL)
		printf("해당 주민등록번호가 존재하지 않습니다\n");
	else {
		printf("주민등록번호: %d \n", p->ssn);
		printf("이름: %s \n", p->name);
		printf("주소: %s \n\n", p->addr);
	}
}

Person* MakePersonData(int ssn, const char name[], const char addr[])
{
	Person* newP = (Person*)malloc(sizeof(Person));
	newP->ssn = ssn;
	strcpy(newP->name, name);
	strcpy(newP->addr, addr);

	return newP;
}