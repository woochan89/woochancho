#include"ArrayList.h"

void main()
{
	List list;
	ArrayList Array;
	int Sum=0;
	Array.ListInit(&list);//초기화
	for (int i = 1; i <= 10; i++)
		Array.LInsert(&list, i);//삽입

	int Num;
	Array.LFirst(&list, &Num);

	do
	{
		Sum += Num;
	} while (Array.LNext(&list,&Num));//합산

	cout << "1부터 9까지의 합은 " << Sum << endl<<endl;

	Array.RCurrentP(&list);

	for (int i = 0; i < 10; i++)
	{
		if (Array.LCheck(list) % 2 == 0 || Array.LCheck(list) % 3 == 0)
			Array.LRemove(&list);
		else
			Array.AddCurrentP(&list);
	}
	Array.RCurrentP(&list);
	cout << "2와 3의 배수를 삭제후 남은 데이터" << endl;
	while (Array.ShowData(&list)) {};


}