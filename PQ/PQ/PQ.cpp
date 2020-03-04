#include "PQ.h"


void PQInit(Heap *h, PriorityComp func) {
	HInit(h, func);
}

bool PQisEmpty(Heap *h)
{
	return HisEmpty(h);
}

void Penqueue(Heap *h, Data data) {
	Hinsert(h, data);
}

Data Pdequeue(Heap *h) {
	return Hdelete(h);
}
