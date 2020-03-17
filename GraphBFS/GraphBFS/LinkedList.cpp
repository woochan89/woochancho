#include "LinkedList.h"
#include<stdlib.h>

//초기화
void ListInit(List *list)
{
	list->head = (Node*)malloc(sizeof(Node));
	list->cur = NULL;
	list->before = NULL;
	list->numOfdata = 0;
	list->comp = NULL;
}

//삽입
void LInsert(List * list, Data data)
{
	if (list->comp == NULL)
		FInsert(list, data);
	else SInsert(list, data);
}

void FInsert(List* list, Data data)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = list->head->next;
	list->head->next = newNode;
	list->numOfdata++;
}

void SInsert(List* list, Data data)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	Node* pred = list->head;
	newNode->data = data;

	while (pred->next != NULL && list->comp(data, pred->next->data) != 0)
		pred = pred->next;

	newNode->next = pred->next;
	pred->next = newNode;
	list->numOfdata++;
}

//조회
bool LFirst(List *list, Data &data)
{
	if (list->numOfdata == 0)
		return false;

	list->before = list->head;
	list->cur = list->head->next;
	data = list->cur->data;
	return true;
}

bool LNext(List *list, Data &data)
{
	if (list->cur->next == NULL)
		return false;

	list->before = list->cur;
	list->cur = list->cur->next;
	data = list->cur->data;
	return true;
}

//삭제
Data LRemove(List *list)
{
	Data rData=list->cur->data;
	Node *rNode=list->cur;

	list->before->next = list->cur->next;
	list->cur = list->before;

	free(rNode);
	list->numOfdata--;

	return rData;
}

void SetSortRule(List* list, int(*comp)(Data d1, Data d2))
{
	list->comp = comp;
}
