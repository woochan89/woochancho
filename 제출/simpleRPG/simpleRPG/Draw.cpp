#include "Draw.h"



Draw::Draw()
{
}

void Draw::showStat(ObjectStat* stat)
{
	cout << " " << stat->Name << "  ���� : " << stat->Lv << endl;
	cout << " ���ݷ� : " << stat->Atk/*<<"  �ֹ��� : "<< stat ->*/ << "  ���� : " << stat->Def << endl;
	cout << " HP : " << stat->Hp << "/" << stat->MaxHp << "  MP" << stat->Mp << "/" << stat->MaxMp << endl;
}

void Draw::showSkill(ObjectSkill* skill)
{
	cout << " " << skill->Name << "  ������ : " << skill->Dmg << endl;
	cout << " �Ҹ�MP : " << skill->MpConsumtion<<"Ÿ�� : ";
	if (skill->Target == ONE_ENEMY)
		cout << "����" << endl;
	else if (skill->Target == ALL_ENEMY)
		cout << "��ü" << endl;
}

void Draw::showEquipment()
{

}

Draw::~Draw()
{
}
