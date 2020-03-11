#include "Person.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int GetSSN(Person* p)
{
	return p->ssn;
}

void ShowPerInfo(Person* p)
{
	if (p == NULL)return;
	printf("%s\n", p->name);
	printf("%d\n", p->ssn);
	printf("%s\n\n", p->addr);
}

Person* MakePersonData(int ssn, const char* name, const char* addr)
{
	Person* newPerson = (Person*)malloc(sizeof(Person));
	newPerson->ssn = ssn;
	strcpy(newPerson->name, name);
	strcpy(newPerson->addr, addr);
	return newPerson;
}
