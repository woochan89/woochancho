#include"Table.h"

int func(Key k) {
	return k % 100;
}

int main()
{
	Table tbl;
	Value v;
	TBLInit(&tbl, func);
	TBLInsert(&tbl, 900101, MakePersonData(900101, "������", "�λ�úλ�����"));
	TBLInsert(&tbl, 900102, MakePersonData(900102, "������", "�λ�úλ�����"));

	ShowPerInfo(TBLSearch(&tbl, 900101));

	TBLDelete(&tbl, 900101);

	ShowPerInfo(TBLSearch(&tbl, 900101));

	return 0;
}