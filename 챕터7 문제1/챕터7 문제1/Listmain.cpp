#include"ArrayList.h"

void main()
{
	List list;
	ArrayList Array;
	int Sum=0;
	Array.ListInit(&list);//�ʱ�ȭ
	for (int i = 1; i <= 10; i++)
		Array.LInsert(&list, i);//����

	int Num;
	Array.LFirst(&list, &Num);

	do
	{
		Sum += Num;
	} while (Array.LNext(&list,&Num));//�ջ�

	cout << "1���� 9������ ���� " << Sum << endl<<endl;

	Array.RCurrentP(&list);

	for (int i = 0; i < 10; i++)
	{
		if (Array.LCheck(list) % 2 == 0 || Array.LCheck(list) % 3 == 0)
			Array.LRemove(&list);
		else
			Array.AddCurrentP(&list);
	}
	Array.RCurrentP(&list);
	cout << "2�� 3�� ����� ������ ���� ������" << endl;
	while (Array.ShowData(&list)) {};


}