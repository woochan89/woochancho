#include"tree.h"

//출력
void PrintData(BTreeNode *bt)
{
	if (bt == NULL) return;
	cout << bt->data << endl;
}
//삭제
void DeleteTree(BTreeNode* bt)
{
	if (bt == NULL) return;
	free(bt);
	bt = NULL;
	cout << "노드 할당해제" << endl;
}


int main(void) 
{
	BTreeNode* bt1 = MakeBTreeNode();

	InputData(bt1, 1);
	InputData(bt1, 2);
	InputData(bt1, 3);

	InorderTraverse(bt1, PrintData);//데이터 중위순회 출력
	InorderTraverse(bt1, DeleteTree);//데이터 중위순회 삭제
}