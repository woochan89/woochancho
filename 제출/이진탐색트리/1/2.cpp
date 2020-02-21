#include"tree.h"

//���
void PrintData(BTreeNode *bt)
{
	if (bt == NULL) return;
	cout << bt->data << endl;
}
//����
void DeleteTree(BTreeNode* bt)
{
	if (bt == NULL) return;
	free(bt);
	bt = NULL;
	cout << "��� �Ҵ�����" << endl;
}


int main(void) 
{
	BTreeNode* bt1 = MakeBTreeNode();

	InputData(bt1, 1);
	InputData(bt1, 2);
	InputData(bt1, 3);

	InorderTraverse(bt1, PrintData);//������ ������ȸ ���
	InorderTraverse(bt1, DeleteTree);//������ ������ȸ ����
}