#include<stdio.h>

typedef struct _empInfo
{
	int empNum;
	int age;
} EmpInfo;

int main()
{
	EmpInfo empInfoArr[1000];
	EmpInfo e1;
	int eNum;

	printf("����� ���� �Է�:");
	scanf("%d %d", &(e1.empNum), &(e1.age));
	empInfoArr[e1.empNum] = e1;

	printf("Ȯ���ϰ��� ������ ��� �Է�: ");
	scanf("%d", &eNum);

	e1 = empInfoArr[eNum];
	printf("��� %d, ���� %d \n", e1.empNum, e1.age);

	return 0;
}