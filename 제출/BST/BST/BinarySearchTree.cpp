#include "BinarySearchTree.h"


void BSTMakeAndInit(BTreeNode ** pRoot)
{
	*pRoot = NULL;
}

// ��忡 ����� ������ ��ȯ
BSTData BSTGetNodeData(BTreeNode * bst)
{
	return GetData(bst);
}

// BST�� ������� ������ ����(����� �������� ����)
void BSTInsert(BTreeNode** pRoot, BSTData data)
{
	BTreeNode *pNode=NULL;
	BTreeNode *cNode=*pRoot;
	BTreeNode *nNode=NULL;

	//�� ��ġ ã��
	while (cNode != NULL) {
		if (data == GetData(cNode))return;
		pNode = cNode;
		if (GetData(cNode) > data)
			cNode = GetLeftSubTree(cNode);
		else cNode = GetRightSubTree(cNode);
	}

	//nNode ���� �� �����ͻ���
	nNode = MakeBTreeNode();
	SetData(nNode, data);

	//���� ������ ũ����ؼ� �ֱ�
	if (pNode != NULL)
	{
		if (GetData(pNode) > data)
			MakeLeftSubTree(pNode, nNode);
		else MakeRightSubTree(pNode, nNode);
	}
	else	//��Ʈ����� ���� ��ġ�� �ٷ� nNode�ֱ�
		*pRoot = nNode;
}

// BST�� ������� ������ Ž��
BTreeNode* BSTSearch(BTreeNode * bst, BSTData target)
{
	while (bst != NULL) {
		if (bst->data == target)
			break;
		else if (bst->data < target)
			bst = bst->right;
		else bst = bst->left;
	}
	return bst;
}