#include "tree.h"

//초기화
BTreeNode* MakeBTreeNode()
{
	BTreeNode* newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
	newNode->data = NULL;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
//인풋
void InputData(BTreeNode *bt, BTData data)
{
	if(bt->data==NULL)
	bt->data = data;
	else if (bt->left == NULL){
		bt->left = MakeBTreeNode();
		InputData(bt->left, data);
	}
	else if (bt->right == NULL) {
		bt->right = MakeBTreeNode();
		InputData(bt->right, data);
	}
	else {
		cout << "루트 노드가 비어있지 않고 공집합 노드도 없습니다"<<endl;
		system("pause");
	}
}

//조회

void InorderTraverse(BTreeNode *bt,func function)
{
	if (bt == NULL)return;
	BTreeNode* tmpBTNode=bt->right;
	InorderTraverse(bt->left, function);
	function(bt);
	InorderTraverse(tmpBTNode, function);
}

