#include"CircularLinkedList.h"

int main()
{
	List list;
	int data;

	//�ʱ�ȭ
	Linit(&list);

	//����
	for (int i = 3; i <= 5; i++)Linsert(&list, i);
	for (int i = 2; i > 0; i--)LFinsert(&list, i);

	//���
	if (Lfirst(&list, &data)) {
		printf("%d ", data);
		while (Lnext(&list, &data)) {
			printf("%d ", data);
		}
		printf("\n");
	}

	//����
	if (Lfirst(&list, &data)) {
		if (data % 2 == 0)
			Lremove(&list);
		while (Lnext(&list, &data)) {
			if (data % 2 == 0)
				Lremove(&list);
		}
		printf("\n");
	}

	//���
	if (Lfirst(&list, &data)) {
		printf("%d ", data);
		while (Lnext(&list, &data)) {
			printf("%d ", data);
		}
		printf("\n");
	}

	//�Ҵ�����
	if (list.tail != NULL) {
		Node *dNode = list.tail->next;
		Node *dnNode = list.tail->next->next;
		free(dNode);
		list.tail->next = NULL;
		while (dnNode!=NULL)
		{
			dNode = dnNode;
			dnNode = dnNode->next;
			free(dNode);
		}
	}

	return 0;
}