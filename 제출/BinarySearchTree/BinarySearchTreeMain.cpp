#include"BinarySearchTree.h"
#include"iostream"
using namespace std;

int main()
{
	BTreeNode *BT;
	BSTData data=true;
	BSTMakeAndInit(&BT);
	while (data != 0) {
		cout << "숫자 입력(입력종료:0) : ";
		cin >> data;
		BSTInsert(&BT, data);
	}
	while (true) {
		cout << "찾는 숫자 입력(종료:0) : ";
		cin >> data;
		if (data == 0)
			break;
		if (BSTSearch(BT, data) != NULL)
			cout <<  "해당 숫자가 존재 합니다" << endl;
		else cout << "해당 숫자가 존재하지 않습니다" << endl;
	}
	return 0;
}