#ifndef _LINKEDLISTQUEUE_
#define _LINKEDLISTQUEUE_

#include<iostream>

typedef struct _node{
	int data;
	struct _node *next;
}Node;

typedef struct _linkdelistQ {
	Node *front;
	Node *rear;
}LQ;

void LQinit(LQ *q);

void Enqueue(LQ *q, int data);

int Dequeue(LQ *q);

int LQpeek(LQ *q);

#endif // !_LINKEDLISTQUEUE_
