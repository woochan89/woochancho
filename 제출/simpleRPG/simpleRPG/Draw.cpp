#include "Draw.h"



Draw::Draw()
{
}

void Draw::showStat(ObjectStat* stat)
{
	cout << " " << stat->Name << "  레벨 : " << stat->Lv << endl;
	cout << " 공격력 : " << stat->Atk/*<<"  주문력 : "<< stat ->*/ << "  방어력 : " << stat->Def << endl;
	cout << " HP : " << stat->Hp << "/" << stat->MaxHp << "  MP" << stat->Mp << "/" << stat->MaxMp << endl;
}

void Draw::showSkill(ObjectSkill* skill)
{
	cout << " " << skill->Name << "  데미지 : " << skill->Dmg << endl;
	cout << " 소모MP : " << skill->MpConsumtion<<"타겟 : ";
	if (skill->Target == ONE_ENEMY)
		cout << "단일" << endl;
	else if (skill->Target == ALL_ENEMY)
		cout << "전체" << endl;
}

void Draw::showEquipment()
{

}

Draw::~Draw()
{
}
