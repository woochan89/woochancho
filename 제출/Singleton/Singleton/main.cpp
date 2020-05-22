#include "Stdmanager.h"
#include"Singleton.h"

void main()
{
	int Select;
	while (1)
	{
		system("cls");
		cout << "1. 학생 등록" << endl;
		cout << "2. 전체 학생정보 출력" << endl;
		cout << "3. 학생 번호 검색" << endl;
		cout << "4. 학생 이름 검색" << endl;
		cout << "5. 등급별 출력" << endl;
		cout << "0. 종료" << endl;
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