#include"BinarySearchTree.h"

int main()
{
	BTreeNode *BSTroot;
	int num=-1;

	BSTMakeAndInit(&BSTroot);

	while (num != 0) {
		printf("숫자 입력(종료 : 0) : ");
		scanf("%d", &num);
		BSTInsert(&BSTroot, num);
	}
	printf("입력 종료\n\n");
	while (true) {
		printf("찾는 숫자 입력(종료 : 0) : ");
		scanf("%d", &num);
		if (num == 0)
			break;
		if (BSTSearch(BSTroot, num) != NULL)
			printf("찾는 숫자가 있습니다\n");
		else printf("찾는 숫자가 없습니다\n");
	}
	printf("종료\n");
	return 0;
}