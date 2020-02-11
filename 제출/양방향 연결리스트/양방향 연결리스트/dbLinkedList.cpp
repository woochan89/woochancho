#include "dbLinkedList.h"

void ListInit(List* plist)
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->tail = (Node*)malloc(sizeof(Node));
	plist->tail->prev = NULL;
	plist->cur = NULL;
	plist->numOfData = 0;
}

void LInsert(List* plist, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	if (plist->numOfData == 0)
	{
		newNode->prev = plist->head;
		plist->head->next = newNode;
	}
	else {
		newNode->prev = plist->tail->prev;
		plist->tail->prev->next = newNode;
	}
	newNode->next = plist->tail;
	plist->tail->prev = newNode;
	plist->numOfData++;
}

int LFirst(List* plist, Data* pdata) {
	if (plist->numOfData == 0)
		return 0;
	plist->cur = plist->head->next;
	*pdata = plist->cur->data;
	return 1;
}

int LNext(List* plist, Data* pdata) {
	if (plist->cur->next == plist->tail)
		return 0;
	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return 1;

}

Data LRemove(List* plist) {
	Node *tmpNode = plist->cur;
	Data tmpData=plist->cur->data;

	if (plist->numOfData == 0) 
		return 0;
	else if (plist->numOfData == 1) {
		plist->head->next = NULL;
		plist->tail->prev = NULL;
		plist->cur = NULL;
	}
	else {
		plist->cur->prev->next = plist->cur->next;
		plist->cur->next->prev = plist->cur->prev;
		plist->cur = plist->cur->prev;
	}
	free(tmpNode);
	return tmpData;
}

int LCount(List* plist) {
	return plist->numOfData;
}
