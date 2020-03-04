#include"PQ.h"
#include<string.h>
bool DataPC(Data D1, Data D2) {
	return (strlen(D2) - strlen(D1));
}

int main()
{
	string a;
	PQueue pq;
	PQInit(&pq, DataPC);
	Data D1='a';
	Penqueue(&pq, "woochan");



	return 0;
}