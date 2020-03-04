#ifndef _PRIORITY_QUEUE_
#define _PRIORITY_QUEUE_

#include"Heap.h"

typedef Heap PQueue;

void PQInit(Heap *h, PriorityComp func);

bool PQisEmpty(Heap *h);

void Penqueue(Heap *h, Data data);

Data Pdequeue(Heap *h);



#endif // _PRIORITY_QUEUE_