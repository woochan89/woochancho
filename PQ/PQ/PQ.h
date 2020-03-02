#ifndef _PRIORITY_QUEUE_
#define _PRIORITY_QUEUE_

#include<iostream>
#define HEAP_LEN 100

typedef char Data;
typedef int PriorityComp(Data, Data);



typedef struct _heap {
	PriorityComp *func;
	int numOfdata;
	Data heapArr[HEAP_LEN];
}Heap;

void PQInit(Heap *h);

bool PQisEmpty(Heap *h);

inline int GetParentIDX(int idx) { return idx / 2; }

inline int GetLChildIDX(int idx) { return idx * 2; }

inline int GetRChildIDX(int idx) { return idx * 2 + 1; }

int GetHiPriChildIDX(Heap *h, int idx);

void Penqueue(Heap *h, Data data);

Data Pdequeue(Heap *h);



#endif // _PRIORITY_QUEUE_