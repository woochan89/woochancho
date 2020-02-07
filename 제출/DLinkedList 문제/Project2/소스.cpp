#include"DLinkedList.h"

int Comp(Node *Before, Node *Compare)//X��ǥ ���� �������� ��
{
	if (Before == NULL)//���� ��尡 NULL�̸� 0 ��ȯ
		return 0;
	int num;
	(Before->data.xpos > Compare->data.xpos) ? num = 0 : num = 1;
	return num;
}

int main()
{
	List list;
	Point tmp;
	Point comp;

	init(&list);//�ʱ�ȭ
	SetFunc(&list, Comp);

	for (int i = 1; i <= 3; i++) {//����Ʈ�� ������ ����
		tmp = InputPos(i, i + 1);
		ArrayInputData(&list, tmp);
	}
	for (int i = 1; i <= 2; i++) {//����Ʈ�� ������ ����
		tmp = InputPos(i, i + 2);
		ArrayInputData(&list, tmp);
	}


	printf("������ ���� : %d\n", list.numOfdata);//������ ���
	if (Lfirst(&list, &tmp))//numOfdata�� 0�� �ƴ϶�� ����
	{
		ShowPos(tmp);
		while (Lnext(&list, &tmp))
			ShowPos(tmp);
	}

	//������ ����
	printf("x�� 2�� ��� ������ ����\n");
	if (Lfirst(&list, &tmp))//numOfdata�� 0�� �ƴ϶�� ����
	{
		comp = InputPos(2, 0);
		if (CompPos(tmp, comp) == 1 || CompPos(tmp, comp) == 3)
		{
			Lremove(&list, &tmp);
			printf("%d, %d ����\n", tmp.xpos, tmp.ypos);
		}
		while (Lnext(&list, &tmp))
		{
			if (CompPos(tmp, comp) == 1 || CompPos(tmp, comp) == 3)
			{
				Lremove(&list, &tmp);
				printf("%d, %d ����\n", tmp.xpos, tmp.ypos);
			}
		}
	}
	printf("���� ������ ���� : %d\n", list.numOfdata);

	Node *dNode = list.head->next;
	Node *dnNode = list.head->next->next;
	delete list.head;
	delete dNode;
	while (dnNode!=NULL)
	{
		dNode = dnNode;
		dnNode = dnNode->next;
		delete dNode;
	}

	return 0;
}