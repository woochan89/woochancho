#include <iostream>
#include<algorithm>
using namespace std;

int BinarySearch(int ar[], int first, int last, int target, int &opCount)
{
	if (first > last) return -1;

	int mid;

	opCount++;
	mid = (first + last) / 2;
	if (target == ar[mid])
	{
		return mid;
	}
	else
	{
		if (target > ar[mid])
			first = mid + 1;
		else
			last = mid - 1;
		BinarySearch(ar, first, last, target, opCount);
	}
}

int BSearch(int ar[], int len, int target)
{
	int first = 0;
	int last = len - 1;
	
	int opCount = 0;   // �񱳿����� Ƚ���� ���

	int find = BinarySearch(ar, first, last, target, opCount);

	cout << "�񱳿��� Ƚ��: " << opCount << endl;  // Ž�� ���� �� ����Ƚ�� ���
	return find;
}

int main(void)
{
	int arr1[500] = { 0, };    // ��� ��� 0���� �ʱ�ȭ
	int arr2[5000] = { 0, };    // ��� ��� 0���� �ʱ�ȭ
	int arr3[50000] = { 0, };    // ��� ��� 0���� �ʱ�ȭ
	int idx;

	arr1[380] = 1;

	sort(arr1, arr1 + 500);

	// ������� ���� ���� 1�� ã����� ���
	idx = BSearch(arr1, sizeof(arr1) / sizeof(int), 1);

	if (idx == -1)
		cout << "Ž�� ���� " << endl << endl;
	else
		cout << "Ÿ�� ���� �ε���: " << idx << endl << endl;

	// ������� ���� ���� 2�� ã����� ���
	idx = BSearch(arr2, sizeof(arr2) / sizeof(int), 2);

	if (idx == -1)
		cout << "Ž�� ����" << endl << endl;
	else
		cout << "Ÿ�� ���� �ε���: " << idx << endl << endl;

	// ������� ���� ���� 3�� ã����� ���
	idx = BSearch(arr3, sizeof(arr3) / sizeof(int), 3);

	if (idx == -1)
		cout << "Ž�� ���� " << endl << endl;
	else
		cout << "Ÿ�� ���� �ε���: " << idx << endl << endl;

	return 0;
}