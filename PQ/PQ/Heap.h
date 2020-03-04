#ifndef _HEAP_
#define _HEAP

#define HEAP_LEN 100
#include<string>
using namespace std;

typedef string Data;
typedef bool PriorityComp(Data D1, Data D2);


typedef struct _heap {
	PriorityComp *func;
	int numOfdata;
	Data heapArr[HEAP_LEN];
}Heap;


void HInit(Heap *h,PriorityComp func);

bool HisEmpty(Heap *h);

inline int GetParentIDX(int idx) { return idx / 2; }

inline int GetLChildIDX(int idx) { return idx * 2; }

inline int GetRChildIDX(int idx) { return idx * 2 + 1; }

int GetHiPriChildIDX(Heap *h, int idx);

void Hinsert(Heap *h, Data data);

Data Hdelete(Heap *h);



#endif // !_HEAP_
