#ifndef __PERSON__
#define __PERSON__
#include<stdio.h>
#define MAX 50

typedef struct _person {
	int ssn;
	char name[MAX];
	char addr[MAX];
}Person;

//�Ҽȳѹ� ��ȯ
inline int Getssn(Person p) { return p.ssn; }

//������ ���
void PrintPerson(Person p);

//������ �Է�
Person* InputPerson(int ssn, const char name[], const char addr[]);

#endif // !__PERSON__
