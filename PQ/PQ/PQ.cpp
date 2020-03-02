#include "PQ.h"


void PQInit(Heap *h, PriorityComp func) {
	h->numOfdata = 0;
	h->func = ;
}

bool PQisEmpty(Heap *h)
{
	if (h->numOfdata == 0)
		return 1;
	else return 0;
}

int GetHiPriChildIDX(Heap *h, int idx) {

}

void Penqueue(Heap *h, Data data);

Data Pdequeue(Heap *h);
