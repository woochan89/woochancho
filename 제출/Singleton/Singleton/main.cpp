#include "Stdmanager.h"
#include"Singleton.h"

void main()
{
	int Select;
	while (1)
	{
		system("cls");
		cout << "1. �л� ���" << endl;
		cout << "2. ��ü �л����� ���" << endl;
		cout << "3. �л� ��ȣ �˻�" << endl;
		cout << "4. �л� �̸� �˻�" << endl;
		cout << "5. ��޺� ���" << endl;
		cout << "0. ����" << endl;
		cin >> Select;
		switch (Select)
		{
		case 1:
			Stdmanager::GetInstance()->Setstudent();
			break;
		case 2:
			Stdmanager::GetInstance()->Display();
			break;
		case 3:
			Stdmanager::GetInstance()->Findnumber();
			break;
		case 4:
			Stdmanager::GetInstance()->Findname();
			break;
		case 5:
			Stdmanager::GetInstance()->Findclass();
			break;
		case 0:
			return;
		}
	}

}