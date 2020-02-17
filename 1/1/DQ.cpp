#include "DQ.h"

void DQinit(DQ *q) {
	q->head = NULL;
	q->tail = NULL;
}

void DQaddfirst(DQ *q, Data data) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	if (q->head == NULL) 
		q->tail = newNode;
	else
		newNode->next = q->head;
	q->head = newNode;
}

void DQaddlast(DQ *q, Data data) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	if (q->head == NULL)
		q->head = newNode;
	else
		q->tail->next=newNode;
	q->tail = newNode;
}

Data DQremovefirst(DQ *q) {
	if (q->head == NULL)
	{
		printf("데이터가 없습니다\n");
		exit(-1);
	}
	Node *tmpNode=q->head;
	Data tmpData = q->head->data;



}

Data DQremovelast(DQ *q) {

}

Data DQgetfirst(DQ *q) {

}

Data DQgetlast(DQ *q) {

}
