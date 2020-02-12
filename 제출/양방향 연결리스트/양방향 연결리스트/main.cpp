#include"dbLinkedList.h"

int main()
{
	List list;
	Data data;

	//�ʱ�ȭ
	ListInit(&list);
	//�Է�
	LInsert(&list, 1);
	LInsert(&list, 2);
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	//���
	if (LFirst(&list, &data)) {
		printf("%d\n", data);
		while (LNext(&list, &data)) 
			printf("%d\n", data);
		printf("\n");
	}
	//����
	if (LFirst(&list, &data)) {
		if(data % 2 == 0)
		LRemove(&list);
		while (LNext(&list, &data))
			if (data % 2 == 0)
				LRemove(&list);
	}
	//���
	printf("2����� ������ ���\n");
	if (LFirst(&list, &data)) {
		printf("%d\n", data);
		while (LNext(&list, &data))
			printf("%d\n", data);
		printf("\n");
	}
	//�Ҵ�����
	Node *dNode = list.head;
	Node *dnNode = list.head->next;
	free(list.head);
	while (dnNode != NULL && dnNode != list.tail) {
		dNode = dnNode;
		dnNode = dnNode->next;
		free(dNode);
	}
	free(list.tail);




	return 0;
}