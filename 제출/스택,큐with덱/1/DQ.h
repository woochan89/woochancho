#ifndef _DE_QUE_
#define _DE_QUE_
#include<iostream>
typedef int Data;

typedef struct _node {
	Data data;
	struct _node *prev;
	struct _node *next;
}Node;

typedef struct _deque {
	Node *head;
	Node *tail;
}DQ;

void DQinit(DQ *q);
bool DQempty(DQ q);
void DQaddfirst(DQ *q, Data data);
void DQaddlast(DQ *q, Data data);

Data DQremovefirst(DQ *q);
Data DQremovelast(DQ *q);

Data DQgetfirst(DQ *q);
Data DQgetlast(DQ *q);

#endif // !_DEQUE_
