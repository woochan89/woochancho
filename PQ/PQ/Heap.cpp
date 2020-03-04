#include "Heap.h"

void HInit(Heap *h, PriorityComp func) {
	h->numOfdata = 0;
	h->func = func;
}

bool HisEmpty(Heap *h) {
	if (h->numOfdata == 0)
		return true;
	else return false;
}

int GetHiPriChildIDX(Heap *h, int idx) {
	if (GetLChildIDX(idx) > h->numOfdata)
		return 0;

	else if (GetLChildIDX(idx) == h->numOfdata)
		return GetLChildIDX(idx);

	else
	{
		if (h->func(h->heapArr[GetLChildIDX(idx)],h->heapArr[GetRChildIDX(idx)]) < 0)
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}
}

void Hinsert(Heap *h, Data data) {
	int idx = h->numOfdata + 1;

	while (idx != 1) {
		if (h->func(data, h->heapArr[GetParentIDX(idx)]) > 0) 
		{
			h->heapArr[idx] = h->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else break;
	}
	h->heapArr[idx] = data;
	h->numOfdata++;
}

Data Hdelete(Heap *h) {
	Data firstData = h->heapArr[1];
	Data lastData = h->heapArr[h->numOfdata];

	int parentIdx = 1;
	int childIdx;

	while (childIdx = GetHiPriChildIDX(h, parentIdx))
	{
		if (h->func(lastData, h->heapArr[childIdx]) >= 0)
			break;
		h->heapArr[parentIdx] = h->heapArr[childIdx];
		parentIdx = childIdx;
	}

	h->heapArr[parentIdx] = lastData;
	h->numOfdata--;
	return lastData;
}
