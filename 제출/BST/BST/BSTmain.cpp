#include"BinarySearchTree.h"

int main()
{
	BTreeNode *BSTroot;
	int num=-1;

	BSTMakeAndInit(&BSTroot);

	while (num != 0) {
		printf("���� �Է�(���� : 0) : ");
		scanf("%d", &num);
		BSTInsert(&BSTroot, num);
	}
	printf("�Է� ����\n\n");
	while (true) {
		printf("ã�� ���� �Է�(���� : 0) : ");
		scanf("%d", &num);
		if (num == 0)
			break;
		if (BSTSearch(BSTroot, num) != NULL)
			printf("ã�� ���ڰ� �ֽ��ϴ�\n");
		else printf("ã�� ���ڰ� �����ϴ�\n");
	}
	printf("����\n");
	return 0;
}