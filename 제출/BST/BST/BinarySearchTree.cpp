#include "BinarySearchTree.h"


void BSTMakeAndInit(BTreeNode ** pRoot)
{
	*pRoot = NULL;
}

// 노드에 저장된 데이터 반환
BSTData BSTGetNodeData(BTreeNode * bst)
{
	return GetData(bst);
}

// BST를 대상으로 데이터 저장(노드의 생성과정 포함)
void BSTInsert(BTreeNode** pRoot, BSTData data)
{
	BTreeNode *pNode=NULL;
	BTreeNode *cNode=*pRoot;
	BTreeNode *nNode=NULL;

	//들어갈 위치 찾기
	while (cNode != NULL) {
		if (data == GetData(cNode))return;
		pNode = cNode;
		if (GetData(cNode) > data)
			cNode = GetLeftSubTree(cNode);
		else cNode = GetRightSubTree(cNode);
	}

	//nNode 생성 및 데이터삽입
	nNode = MakeBTreeNode();
	SetData(nNode, data);

	//왼쪽 오른쪽 크기비교해서 넣기
	if (pNode != NULL)
	{
		if (GetData(pNode) > data)
			MakeLeftSubTree(pNode, nNode);
		else MakeRightSubTree(pNode, nNode);
	}
	else	//루트노드라면 현제 위치에 바로 nNode넣기
		*pRoot = nNode;
}

// BST를 대상으로 데이터 탐색
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