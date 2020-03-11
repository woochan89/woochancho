#ifndef _SLOT_
#define _SLOT_
#include"Person.h"

typedef int Key;
typedef Person* Value;

//상태 이넘
enum Status { EMPTY, DELETED, INUSE };

//슬롯
typedef struct _slot {
	Value value;
	Key key;
	Status status;
}Slot;

#endif // 
