#ifndef _BTREE_
#define _BTREE_
#include<iostream>
using namespace std;
typedef int BTData;

typedef struct _bTreeNode {
	BTData data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
}BTreeNode;

//초기화
BTreeNode* MakeBTreeNode();

//인풋
void InputData(BTreeNode *bt, BTData data);


//typedef void(*func)(BTreeNode*);
typedef void func(BTreeNode*);
//조회
void InorderTraverse(BTreeNode *bt, func function);
#endif // !_BTREE_