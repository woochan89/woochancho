#include"ArrayList.h"
using namespace std;


int main()
{
	ArrayList LinearList;
	List list;
	Ldata num;
	Ldata Sum = 0;
	int max;
	int RemoveNum;

	printf("1���� �� ������ ���ڸ� ���� �Ͻðڽ��ϱ�? : ");
	scanf("%d", &max);
	LinearList.Listinit(&list);// �ʱ�ȭ
	for (int i = 1; i <= max; i++) {// ������ ����
		LinearList.Linsert(&list, i);
	}

	LinearList.Lfirst(&list, &num);
	do
	{
		Sum += num;
	} while (LinearList.Lnext(&list,&num));// ����Ʈ ���ϱ�
	printf("1���� %d������ �հ� : %d\n", max, Sum);

	printf("���� �ϰ� ���� ����� ���ڸ� �Է��ϼ��� : ");
	scanf("%d", &RemoveNum);
	printf("%d�� ����� ������ ��� ���� ��� : ", RemoveNum);
	LinearList.Lfirst(&list, &num);
	do {
		if (num % RemoveNum == 0)
			LinearList.Lremove(&list);
		else
			cout << " [" << num << "] ";

	} while (LinearList.Lnext(&list, &num));

	return 0;
}