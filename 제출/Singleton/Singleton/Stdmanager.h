#pragma once
#include"Singleton.h"
#include<string>
using namespace std;
#define STD_MAX 30

typedef struct Student {
	string name;
	int kor, eng, math, sum;
	float avg;
	int num;
	char Class;
};


class Stdmanager :public Singleton<Stdmanager>
{
private:
	Student *std[STD_MAX];
public:
	void Setstudent();
	void Display();
	void Findnumber();
	void Findname();
	void Findclass();
	void ShowStudent(Student *std);

	Stdmanager();
	~Stdmanager();
};

