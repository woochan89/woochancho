#ifndef _LINKEDLIST_
#define _LINKEDLIST_

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node *next;
}Node;

typedef struct _linkedlist
{
	Node *head;
	Node *cur;
	Node *before;
	int numOfdata;
	int(*comp)(Data d1, Data d2);
}LinkedList;

typedef LinkedList List;

void ListInit(List * list);

void LInsert(List * list, Data data);
void FInsert(List* list, Data data);
void SInsert(List* list, Data data);

int LFirst(List* list, Data& data);
int LNext(List* list, Data& data);

Data LRemove(List* list);

void SetSortRule(List* list, int(*comp)(Data d1, Data d2));

#endif // 
