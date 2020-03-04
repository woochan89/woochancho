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

	printf("문자열 저장방식\n");
	printf("1. 최소 힙\n");
	printf("2. 최대 힙\n");
	scanf("%d", &flag);
	(flag == 1) ? PQInit(&pq, Min) : PQInit(&pq, Max);
	for (int i = 1;;i++) {
		system("cls");
		printf("%d번째 문자열 입력(0입력시 출력) : ", i);
		cin >> tmp;
		if (tmp == "0")
			break;
		Penqueue(&pq, tmp);
	}

	while (!PQisEmpty(&pq))
		cout << Pdequeue(&pq)<<endl;


	return 0;
}