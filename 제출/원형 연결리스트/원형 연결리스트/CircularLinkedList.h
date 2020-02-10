#ifndef _CircularLinkedList_
#define CircularLinkedList
#include<iostream>
#include<stdio.h>


typedef struct _node
{
	int data;
	struct _node *next;
}Node;

typedef struct _list
{
	Node *tail;
	Node *cur;
	Node *before;
	int numOfdata;
}List;

void Linit(List *list);

void Linsert(List *list, int data);

void LFinsert(List *list, int data);

bool Lfirst(List *list, int *data);

bool Lnext(List *list, int *data);

void Lremove(List *list);


#endif // !_CircularLinkedList_
