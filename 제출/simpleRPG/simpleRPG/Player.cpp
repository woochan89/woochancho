#include "Player.h"




Player::Player()
{
	m_Exp = 0;
	m_Condition = NOMAL;
	m_Weapon = NULL;
	m_Armor = NULL;
	m_Accessory = NULL;

}

string Player::ReturnCondition(Condition condition)
{
	if (condition == NOMAL)
		return "����";
	else if (condition == POSION)
		return "�ߵ�";
	else 
		return "����";
}


void Player::notify(string boss_name,Condition condition)
{
	cout << boss_name << "�� " << m_PlayerStat->Name << "���� " ;
	cout << ReturnCondition(condition) << "�����̻��� �ɾ���!" << endl;
}

void Player::GetExp(int exp)
{
	int maxExp = 10 + (m_PlayerStat->Lv) * 2;
	int remainExp;

	cout << exp << "�� ����ġ�� ȹ���Ͽ����ϴ�\n";
	if (m_Exp + exp >= maxExp)
	{
		remainExp = m_Exp + exp - maxExp;
		cout << "������!\n";
		LVup();
	}
	m_Exp += exp;
	system("pause");
}


Player::~Player()
{
}



Warrior::Warrior()
{
}

void Warrior::LVup()
{
	m_PlayerStat->Lv++;
	m_PlayerStat->Atk += 3;
	m_PlayerStat->Def += 2;
	m_PlayerStat->MaxHp += 5;
	m_PlayerStat->MaxMp += 2;
	m_PlayerStat->Hp = m_PlayerStat->MaxHp;
	m_PlayerStat->Mp = m_PlayerStat->MaxMp;
	m_Exp = 0;
}

Warrior::~Warrior()
{

}
