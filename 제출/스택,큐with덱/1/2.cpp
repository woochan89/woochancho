#include"DQ.h"
using namespace std;

int main()
{
	DQ Q;

	DQinit(&Q);

	printf("���� with ��\n");
	for(int i=1;i<=5;i++)
		DQaddlast(&Q, i);
while (!DQempty(Q))
		cout << DQremovelast(&Q) << endl;

	printf("\n\n");
	printf("ť with ��\n");
	for (int i = 1; i <= 5; i++)
		DQaddlast(&Q, i);
	while (!DQempty(Q))
		std::cout << DQremovefirst(&Q) << std::endl;

	return 0;
}