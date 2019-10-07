#include <iostream>
using namespace std;

int BSearchRecur(int ar[], int first, int last, int target)
{
	int mid;
	if (first > last)
		return -1;    // -1�� ��ȯ�� Ž���� ���и� �ǹ�

	mid = (first + last) / 2;    // Ž������� �߾��� ã�´�.

	if (ar[mid] == target)
		return mid;    // �˻��� Ÿ���� �ε��� �� ��ȯ
	else if (target < ar[mid])
		return BSearchRecur(ar, first, mid - 1, target);
	else
		return BSearchRecur(ar, mid + 1, last, target);
}

int main(void)
{
	int arr[] = { 1, 3, 5, 7, 9 };
	int idx;

	idx = BSearchRecur(arr, 0, sizeof(arr) / sizeof(int) - 1, 7);

	if (idx == -1)
		cout << "Ž�� ����" << endl;
	else
		cout << "Ÿ�� ���� �ε���: " << idx << endl;

	idx = BSearchRecur(arr, 0, sizeof(arr) / sizeof(int) - 1, 2);

	if (idx == -1)
		cout << "Ž�� ����" << endl;
	else
		cout << "Ÿ�� ���� �ε���: " << idx << endl;

	return 0;
}