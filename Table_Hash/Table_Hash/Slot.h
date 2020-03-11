#ifndef _SLOT_
#define _SLOT_
#include"Person.h"

typedef int Key;
typedef Person* Value;

//���� �̳�
enum Status { EMPTY, DELETED, INUSE };

//����
typedef struct _slot {
	Value value;
	Key key;
	Status status;
}Slot;

#endif // 
