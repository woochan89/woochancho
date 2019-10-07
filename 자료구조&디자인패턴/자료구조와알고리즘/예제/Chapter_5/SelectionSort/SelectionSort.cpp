#include <stdio.h>

void SelSort(int arr[], int n)
{
	int maxIdx;
	int temp;

	for (int i = 0; i < n - 1; i++)
	{
		maxIdx = i;    // ���� ������ ���� �ռ��� �������� index

		for (int j = i + 1; j < n; j++)   // �ּҰ� Ž��
		{
			if (arr[j] < arr[maxIdx])
				maxIdx = j;
		}

		/* ��ȯ */
		temp = arr[i];
		arr[i] = arr[maxIdx];
		arr[maxIdx] = temp;
	}
}


int main(void)
{
	int arr[4] = { 3, 4, 2, 1 };

	SelSort(arr, sizeof(arr) / sizeof(int));

	for (int i = 0; i < 4; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}