#include"Table.h"

int HashFunc(int k)
{
	return k % 100;
}

int main()
{
	Table tbl;
	TBLinit(&tbl, HashFunc);

	TBLinsert(&tbl,900001,)




	return 0;
}