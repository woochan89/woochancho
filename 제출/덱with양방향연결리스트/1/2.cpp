#include"DQ.h"
using namespace std;

int main()
{
	DQ Q;

	DQinit(&Q);

	for(int i=1;i<=5;i++)
		DQaddlast(&Q, i);

	while (Q.head != NULL) 
		cout << DQremovefirst(&Q) << endl;
	printf("\n\n");
	for (int i = 1; i <= 5; i++)
		DQaddfirst(&Q, i);

	while (Q.head != NULL)
		std::cout << DQremovelast(&Q) << std::endl;

	return 0;
}