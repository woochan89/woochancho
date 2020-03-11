#ifndef __SLOT_H__
#define __SLOT_H__

#include "Person.h"

typedef int		Key;	// Ű ���� �Ǵ� �ֹι�ȣ
typedef Person* Value;	// Person ����ü ������ ��

//�����Ͱ� ��������� ������, ���� ����� ��������, ��ȿ�� �����Ͱ� ����Ǿ��ִ���.
enum SlotStatus { EMPTY, DELETED, INUSE };

typedef struct _slot
{
	Key				key;
	Value			val;
	enum SlotStatus status; // ������ ���¸� ��Ÿ����.
} Slot;

#endif
