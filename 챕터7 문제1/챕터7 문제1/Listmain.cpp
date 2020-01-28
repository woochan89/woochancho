#include"ArrayList.h"

void main()
{
	List list;
	ArrayList Array;
	int Sum=0;
	int Max;


	cout << "1부터 몇 까지의 숫자를 배열로 만드시겠습니까?" << endl;
	cin >> Max;
	Array.ListInit(&list);//초기화
	for (int i = 1; i <= Max; i++)
		Array.LInsert(&list, i);//삽입

	int Num;
	Array.LFirst(&list, &Num);

	do
	{
		Sum += Num;
	} while (Array.LNext(&list,&Num));//합산

	cout << "1부터 "<< Max <<"까지의 합은 " << Sum << endl << endl;

	Array.RCurrentP(&list);

	cout << "삭제하고 싶은 배수의 수를 입력해주세요" << endl;
	cin >> Num;
	for (int i = 0; i < 10; i++)
	{
		if (Array.LCheck(list) % Num == 0)
			Array.LRemove(&list);
		else
			Array.AddCurrentP(&list);
	}
	Array.RCurrentP(&list);
	cout << Num << "의 배수를 삭제후 남은 데이터" << endl;
	while (Array.ShowData(&list)) {};
}