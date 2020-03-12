#ifndef __PERSON__
#define __PERSON__
#include<stdio.h>
#define MAX 50

typedef struct _person {
	int ssn;
	char name[MAX];
	char addr[MAX];
}Person;

//소셜넘버 반환
inline int Getssn(Person p) { return p.ssn; }

//데이터 출력
void PrintPerson(Person p);

//데이터 입력
Person* InputPerson(int ssn, const char name[], const char addr[]);

#endif // !__PERSON__
