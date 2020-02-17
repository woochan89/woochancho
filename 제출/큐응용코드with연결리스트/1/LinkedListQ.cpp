#include "LinkedListQ.h"

void LQinit(LQ *q) {
	q->front = NULL;
	q->rear = NULL;
}

void Enqueue(LQ *q, int data) {
	Node *newData = (Node*)malloc(sizeof(Node));
	newData->data = data;
	newData->next = NULL;
	if (q->front == NULL)
		q->front = newData;
	else
		q->rear->next = newData;
	q->rear = newData;
}

int Dequeue(LQ *q) {
	if (q->front==NULL) {	return -1;	}
	int tmpdata = q->front->data;
	Node *tmp=q->front;
	q->front = q->front->next;
	free(tmp);
	return tmpdata;
}

int LQpeek(LQ *q) {
	return q->front->data;
}
