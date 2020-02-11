#include<stdio.h>
#include<iostream>
using namespace std;

#ifndef _DBLINKEDLIST_
#define _DBLINKEDLIST_


typedef int Data;

typedef struct _node
{
	Data data;
	struct _node* next;
	struct _node* prev;
}Node;

typedef struct _dbDLinkedList
{
	Node* head;
	Node* tail;
	Node* cur;
	int numOfData;
}DBDLinkedList;

typedef DBDLinkedList List;

void ListInit(List* plist);
void LInsert(List* plist, Data data);	// ������ ��带 �߰��Ѵ�.

int LFirst(List* plist, Data* pdata);
int LNext(List* plist, Data* pdata);

Data LRemove(List* plist);		// �ռ� ������ �̷��� ��带 �����Ѵ�.
int LCount(List* plist);

#endif // !_DBLINKEDLIST_
