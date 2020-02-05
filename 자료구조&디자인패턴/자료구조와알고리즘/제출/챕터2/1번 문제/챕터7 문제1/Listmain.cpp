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

	printf("1부터 몇 까지의 숫자를 저장 하시겠습니까? : ");
	scanf("%d", &max);
	LinearList.Listinit(&list);// 초기화
	for (int i = 1; i <= max; i++) {// 데이터 삽입
		LinearList.Linsert(&list, i);
	}

	LinearList.Lfirst(&list, &num);
	do
	{
		Sum += num;
	} while (LinearList.Lnext(&list,&num));// 리스트 합하기
	printf("1부터 %d까지의 합계 : %d\n", max, Sum);

	printf("제외 하고 싶은 배수의 숫자를 입력하세요 : ");
	scanf("%d", &RemoveNum);
	printf("%d의 배수를 제외한 모든 숫자 출력 : ", RemoveNum);
	LinearList.Lfirst(&list, &num);
	do {
		if (num % RemoveNum == 0)
			LinearList.Lremove(&list);
		else
			cout << " [" << num << "] ";

	} while (LinearList.Lnext(&list, &num));

	return 0;
}