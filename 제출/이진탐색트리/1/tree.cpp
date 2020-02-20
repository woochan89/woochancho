#include "tree.h"

//�ʱ�ȭ
BTreeNode* MakeBTreeNode()
{
	BTreeNode* newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
	newNode->data = NULL;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
//��ǲ
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
		cout << "��Ʈ ��尡 ������� �ʰ� ������ ��嵵 �����ϴ�"<<endl;
		system("pause");
	}
}

//��ȸ

void InorderTraverse(BTreeNode *bt,func function)
{
	if (bt == NULL)return;
	BTreeNode* tmpBTNode=bt->right;
	InorderTraverse(bt->left, function);
	function(bt);
	InorderTraverse(tmpBTNode, function);
}

