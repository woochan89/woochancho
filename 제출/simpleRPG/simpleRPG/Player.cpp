#include "Player.h"




Player::Player(string name)
{
	m_cPlayerStat->Name = name;
	m_cPlayerStat->Lv = 1;
}

string Player::ReturnCondition(Condition condition)
{
	if (condition == NOMAL)
		return "����";
	else if (condition == BLEEDING)
		return "����";
	else if (condition == POSION)
		return "�ߵ�";
	else 
		return "ȭ��";
}


void Player::notify(string boss_name,Condition condition)
{

	cout << boss_name << "�� " << m_cPlayerStat->Name << "���� " ;
	cout << condition << "�����̻��� �ɾ���!" << endl;
}

Player::~Player()
{
}



Warrior::Warrior(string name):Player(name)
{
	m_cPlayerStat->Atk = 5;
	m_cPlayerStat->Def = 1;
	m_cPlayerStat->MaxHp = 30;
	m_cPlayerStat->Hp = 30;
	m_cPlayerStat->MaxMp = 10;
	m_cPlayerStat->Mp = 10;
}

Warrior::~Warrior()
{

}
