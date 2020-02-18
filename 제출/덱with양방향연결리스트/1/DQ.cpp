#include "DQ.h"

void DQinit(DQ *q) {
	q->head = NULL;
	q->tail = NULL;
}

void DQaddfirst(DQ *q, Data data) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->prev = NULL;
	newNode->next = q->head;
	if (q->head == NULL) 
		q->tail = newNode;
	else 
		q->head->prev = newNode;
	q->head = newNode;
}

void DQaddlast(DQ *q, Data data) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = q->tail;
	if (q->head == NULL) 
		q->head = newNode;
	else 
		q->tail->next = newNode;
	q->tail = newNode;
}

Data DQremovefirst(DQ *q) {
	if (q->head == NULL){
		printf("데이터가 없습니다\n");
		exit(-1);
	}
	Node *tmpNode=q->head;
	Data tmpData = q->head->data;
	q->head = q->head->next;
	if (q->head != NULL) q->head->prev = NULL;
	else
		q->tail = NULL;
	free(tmpNode);
	return tmpData;
}

Data DQremovelast(DQ *q) {
	if (q->head == NULL){
		printf("데이터가 없습니다\n");
		exit(-1);
	}
	Node *tmpNode = q->tail;
	Data tmpData = q->tail->data;
	q->tail = q->tail->prev;
	if (q->tail != NULL) q->tail->next = NULL;
	else
		q->head = NULL;
	free(tmpNode);
	return tmpData;
}

Data DQgetfirst(DQ *q) {
	if (q->head == NULL){
		printf("데이터가 없습니다\n");
		exit(-1);
	}
	return q->head->data;
}

Data DQgetlast(DQ *q) {
	if (q->head == NULL){
		printf("데이터가 없습니다\n");
		exit(-1);
	}
	return q->tail->data;
}
