#include"BinarySearchTree.h"
#include"iostream"
using namespace std;

int main()
{
	BTreeNode *BT;
	BSTData data=true;
	BSTMakeAndInit(&BT);
	while (data != 0) {
		cout << "���� �Է� : ";
		cin >> data;
		BSTInsert(&BT, data);
	}
	while (true) {
		cout << "ã�� ���� �Է� : ";
		cin >> data;
		if (data == 0)
			break;
		if (BSTSearch(BT, data) != NULL)
			cout <<  "�ش� ���ڰ� ���� �մϴ�" << endl;
		else cout << "�ش� ���ڰ� �������� �ʽ��ϴ�" << endl;
	}
	return 0;
}