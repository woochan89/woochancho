#include "CircularLinkedList.h"

void Linit(List *list) {
	list->tail = NULL;
	list->cur = NULL;
	list->before = NULL;
	list->numOfdata = 0;
}

void Linsert(List *list, int data) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (list->tail == NULL)
	{
		newNode->next = newNode;
		list->tail = newNode;
	}
	else
	{
		newNode->next = list->tail->next;//뉴노드->헤드
		list->tail->next = newNode;//테일->뉴노드
		list->tail = newNode;//테일=뉴노드
	}
	list->numOfdata++;
}

void LFinsert(List *list, int data) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (list->tail == NULL)
	{
		newNode->next = newNode;
		list->tail = newNode;
	}
	else {
		newNode->next = list->tail->next;
		list->tail->next = newNode;
	}
	list->numOfdata++;
}

bool Lfirst(List *list, int *data) {
	if (list->tail == NULL)
		return 0;
	list->before = list->tail;
	list->cur = list->tail->next;
	*data = list->cur->data;
	return 1;
}

bool Lnext(List *list, int *data) {
	if (list->cur == list->tail)
		return 0;
	list->before = list->cur;
	list->cur = list->cur->next;
	*data = list->cur->data;
	return 1;
}

void Lremove(List *list) {
	Node *tmpNode=list->cur;
	int tmpData=tmpNode->data;

	if (list->cur == list->tail){
		if (list->cur == list->cur->next){
			list->tail = NULL;
		}
		else {
			list->tail = list->before;
		}
	}
	list->before->next = list->cur->next;
	list->cur = list->before;
	free(tmpNode);
	list->numOfdata--;
}
