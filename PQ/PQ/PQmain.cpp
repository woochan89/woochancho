#include"PQ.h"
#include<string.h>
#include<iostream>
bool Max(Data D1, Data D2) {
	int num = (D1.length() >= D2.length()) ? 1 : 0;
	return num;
}

bool Min(Data D1, Data D2) {
	int num = (D1.length() <= D2.length()) ? 1 : 0;
	return num;
}


int main()
{
	PQueue pq;
	int flag;
	string tmp;

	printf("���ڿ� ������\n");
	printf("1. �ּ� ��\n");
	printf("2. �ִ� ��\n");
	scanf("%d", &flag);
	(flag == 1) ? PQInit(&pq, Min) : PQInit(&pq, Max);
	for (int i = 1;;i++) {
		system("cls");
		printf("%d��° ���ڿ� �Է�(0�Է½� ���) : ", i);
		cin >> tmp;
		if (tmp == "0")
			break;
		Penqueue(&pq, tmp);
	}

	while (!PQisEmpty(&pq))
		cout << Pdequeue(&pq)<<endl;


	return 0;
}