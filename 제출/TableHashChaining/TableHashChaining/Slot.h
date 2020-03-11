#ifndef __SLOT__
#define __SLOT__
#include"Person.h"

typedef Person Value;
typedef int Key;

typedef struct _slot {
	Value v;
	Key key;
}Slot;

#endif // 
