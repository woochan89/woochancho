#include "Person.h"
#include<string.h>
#include<stdlib.h>

//������ ���
void PrintPerson(Person p)
{
	printf("�ֹε�Ϲ�ȣ : %s\n", p.name);
	printf("�̸� : %d\n", p.ssn);
	printf("�ּ� : %s\n\n", p.addr);
}

//������ �Է�
Person* InputPerson(int ssn, const char name[], const char addr[])
{
	Person * newP = (Person*)malloc(sizeof(Person));

	newP->ssn = ssn;
	strcpy(newP->name, name);
	strcpy(newP->addr, addr);
	return newP;
}