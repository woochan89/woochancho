#include"ArrayList.h"

void main()
{
	List list;
	ArrayList Array;
	int Sum=0;
	int Max;


	cout << "1���� �� ������ ���ڸ� �迭�� ����ðڽ��ϱ�?" << endl;
	cin >> Max;
	Array.ListInit(&list);//�ʱ�ȭ
	for (int i = 1; i <= Max; i++)
		Array.LInsert(&list, i);//����

	int Num;
	Array.LFirst(&list, &Num);

	do
	{
		Sum += Num;
	} while (Array.LNext(&list,&Num));//�ջ�

	cout << "1���� "<< Max <<"������ ���� " << Sum << endl << endl;

	Array.RCurrentP(&list);

	cout << "�����ϰ� ���� ����� ���� �Է����ּ���" << endl;
	cin >> Num;
	for (int i = 0; i < 10; i++)
	{
		if (Array.LCheck(list) % Num == 0)
			Array.LRemove(&list);
		else
			Array.AddCurrentP(&list);
	}
	Array.RCurrentP(&list);
	cout << Num << "�� ����� ������ ���� ������" << endl;
	while (Array.ShowData(&list)) {};
}