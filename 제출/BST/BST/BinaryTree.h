#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int BTData;

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode * left;
	struct _bTreeNode * right;
} BTreeNode;

BTreeNode * MakeBTreeNode(void);
inline BTData GetData(BTreeNode * bt) { return bt->data; }
inline void SetData(BTreeNode * bt, BTData data){ bt->data = data; }

inline BTreeNode * GetLeftSubTree(BTreeNode * bt) { return bt->left; }
inline BTreeNode * GetRightSubTree(BTreeNode * bt) { return bt->right; }

inline void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub) { main->left = sub; }
inline void MakeRightSubTree(BTreeNode * main, BTreeNode * sub) { main->right = sub; }

typedef void VisitFuncPtr(BTData data);

void PreorderTraverse(BTreeNode * bt, VisitFuncPtr action);//전위순회
void InorderTraverse(BTreeNode * bt, VisitFuncPtr action);//중위순회
void PostorderTraverse(BTreeNode * bt, VisitFuncPtr action);//후위순회

#endif
