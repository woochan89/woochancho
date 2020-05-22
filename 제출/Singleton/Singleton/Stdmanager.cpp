#include "Stdmanager.h"

Stdmanager* Stdmanager::m_pThis = NULL;

Stdmanager::Stdmanager()
{
	for (int i = 0; i < STD_MAX; i++)
	{
		std[i] = new Student;
		std[i]->num = NULL;
	}
}


void Stdmanager::Setstudent()
{
	for (int i = 0; i < STD_MAX; i++)
	{
		if (std[i]->num == NULL)
		{
			cout << "이름을 입력 하시오 : ";
			cin >> std[i]->name;
			cout << "3과목의 점수를 입력하시오" << endl;
			cout << "국어 : ";
			cin >> std[i]->kor;
			cout << "영어 : ";
			cin >> std[i]->eng;
			cout << "수학 : ";
			cin >> std[i]->math;
			std[i]->sum = std[i]->kor + std[i]->eng + std[i]->math;
			std[i]->avg = (float)std[i]->sum / 3;
			std[i]->num = i + 1;
			if (std[i]->avg >= 90)
				std[i]->Class = 'A';
			else if (std[i]->avg >= 80)
				std[i]->Class = 'B';
			else if (std[i]->avg >= 70)
				std[i]->Class = 'C';
			else if (std[i]->avg >= 60)
				std[i]->Class = 'D';
			else
				std[i]->Class = 'F';
			return;

		}
	}
	cout << "학생이 전원 등록 되었습니다" << endl;
}

void Stdmanager::Display()
{
	int std_count = 0;
	for (int i = 0; i < 30; i++)
	{
		if (std[i]->num != 0)
		{
			ShowStudent(std[i]);
			std_count++;
		}
	}
	if (std_count == 0)
		cout << "등록된 학생이 없습니다" << endl;
	system("pause");

}

void Stdmanager::Findnumber()
{
	int find_num;
	cout << "찾을 학생의번호를 입력 하시오";
	cin >> find_num;
	for (int i = 0; i < 30; i++)
	{
		if (std[i]->num == find_num)
		{
			ShowStudent(std[i]);
			system("pause");
			return;
		}
	}
	cout << endl << "해당 번호의 학생이 없습니다." << endl;
	system("pause");

}

void Stdmanager::Findname()
{
	string find_name;
	int find_num = 0;
	cout << "찾을 학생의이름을 입력 하시오" << endl;
	cin >> find_name;
	for (int i = 0; i < 30; i++)
	{
		if (std[i]->name == find_name)
		{
			ShowStudent(std[i]);
			find_num++;
		}
	}
	if (!find_num)
		cout << "해당 이름의 학생이 없습니다." << endl;
	system("pause");

}

void Stdmanager::Findclass()
{
	int _find = 0;


	cout << "========= [ A ] =========" << endl;
	for (int i = 0; i < 30; i++)
	{
		if (std[i]->Class == 'A')
		{
			ShowStudent(std[i]);
			_find++;
		}
	}
	cout << "총 " << _find << "명" << endl;
	cout << "=========================" << endl;
	_find = 0;
	cout << "========= [ B ] =========" << endl;
	for (int i = 0; i < 30; i++)
	{
		if (std[i]->Class == 'B')
		{
			ShowStudent(std[i]);
			_find++;
		}
	}
	cout << "총 " << _find << "명" << endl;
	cout << "=========================" << endl;
	_find = 0;
	cout << "========= [ C ] =========" << endl;
	for (int i = 0; i < 30; i++)
	{
		if (std[i]->Class == 'C')
		{
			ShowStudent(std[i]);
			_find++;
		}
	}
	cout << "총 " << _find << "명" << endl;
	cout << "=========================" << endl;
	_find = 0;
	cout << "========= [ D ] =========" << endl;
	for (int i = 0; i < 30; i++)
	{
		if (std[i]->Class == 'D')
		{
			ShowStudent(std[i]);
			_find++;
		}
	}
	cout << "총 " << _find << "명" << endl;
	cout << "=========================" << endl;
	_find = 0;
	cout << "========= [ F ] =========" << endl;
	for (int i = 0; i < 30; i++)
	{
		if (std[i]->Class == 'F')
		{
			ShowStudent(std[i]);
			_find++;
		}
	}
	cout << "총 " << _find << "명" << endl;
	cout << "=========================" << endl;
	system("pause");

}

void Stdmanager::ShowStudent(Student *std)
{
	cout << "----------------------" << endl;
	cout << std->num << "번 학생" << endl;
	cout << "이름 : " << std->name << endl;
	cout << "국어 점수 : " << std->kor << endl << "수학 점수 : " << std->math << endl << "영어 점수 : " << std->eng << endl;
	cout << "합계 점수 : " << std->sum << "\t 평균점수 : " << std->avg << endl;
	cout << "등급 : [ " << std->Class << "]" << endl << endl;
}


Stdmanager::~Stdmanager()
{
	for (int i = 0; i < STD_MAX; i++)
		delete std[i];
}
