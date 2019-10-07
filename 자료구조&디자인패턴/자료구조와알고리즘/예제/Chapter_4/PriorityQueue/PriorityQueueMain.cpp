#include <stdio.h>
#include<string>
#include<iostream>
#include "PriorityQueue.h"
using namespace std;

int DataPriorityComp(string str1, string str2)
{
	return str2.length() - str1.length();
}

int main(void)
{
	PQueue pq;
	PQueueInit(&pq, DataPriorityComp);

	PEnqueue(&pq, "Adobe");
	PEnqueue(&pq, "Bill");
	PEnqueue(&pq, 'C');
	printf("%c \n", PDequeue(&pq));

	PEnqueue(&pq, 'A');
	PEnqueue(&pq, 'B');
	PEnqueue(&pq, 'C');
	printf("%c \n", PDequeue(&pq));

	while (!PQIsEmpty(&pq))
		printf("%c \n", PDequeue(&pq));

	system("pause");

	return 0;
}
