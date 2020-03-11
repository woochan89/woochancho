#ifndef __TABLE__
#define __TABLE__
#include"DLinkedList.h"

typedef Key (func)(Key);

typedef struct _table {
	Slot A;
	func func;

}Table;


#endif // !__TABLE__
