#include "DLinkedList.h"

//�ʱ�ȭ
void listInit(List *list) {

}

//����
void InsertData(List *list, Slot data);

//üũ
bool LIsEmpty(List list);

//�۽�Ʈ��ȸ
Slot Lfirst(List *list, Slot data);

//�ؽ�Ʈ��ȸ
Slot Lnext(List *list, Slot data);

//����
void Lremove(List *list, Slot data);
