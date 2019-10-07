#include <stdio.h>
#include "BinaryTree.h"

int main(void)
{
	BTreeNode* bt1 = MakeBTreeNode();	// ��� bt1 ����
	BTreeNode* bt2 = MakeBTreeNode();	// ��� bt2 ����
	BTreeNode* bt3 = MakeBTreeNode();	// ��� bt3 ����
	BTreeNode* bt4 = MakeBTreeNode();	// ��� bt4 ����

	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);

	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);

	//bt1�� ���� �ڽ� ����� ������ ���
	printf("%d \n", GetData(GetLeftSubTree(bt1)));

	//bt1�� ���� �ڽ� ����� ���� �ڽ� ����� ������ ���
	printf("%d \n", GetData(GetLeftSubTree(GetLeftSubTree(bt1))));

	DeleteTree(bt2);

	return 0;
}