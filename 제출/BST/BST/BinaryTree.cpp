#include "BinaryTree.h"
#include<iostream>



BTreeNode * MakeBTreeNode(void) 
{
	BTreeNode *newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
	newNode->data = NULL;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}


void PreorderTraverse(BTreeNode * bt, VisitFuncPtr action)
{
	if (bt->data == NULL)
		return;
	action(bt->data);
	PreorderTraverse(bt->left, action);
	PreorderTraverse(bt->right, action);
}
void InorderTraverse(BTreeNode * bt, VisitFuncPtr action)
{
	if (bt->data == NULL)
		return;
	PreorderTraverse(bt->left, action);
	action(bt->data);
	PreorderTraverse(bt->right, action);
}
void PostorderTraverse(BTreeNode * bt, VisitFuncPtr action)
{
	if (bt->data == NULL)
		return;
	PreorderTraverse(bt->left, action);
	PreorderTraverse(bt->right, action);
	action(bt->data);
}