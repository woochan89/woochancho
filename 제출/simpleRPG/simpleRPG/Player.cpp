#include "Player.h"




Player::Player(string name)
{
	m_cPlayerStat->Name = name;
	m_cPlayerStat->Lv = 1;
}

string Player::ReturnCondition(Condition condition)
{
	if (condition == NOMAL)
		return "정상";
	else if (condition == BLEEDING)
		return "출혈";
	else if (condition == POSION)
		return "중독";
	else 
		return "화상";
}


void Player::notify(string boss_name,Condition condition)
{

	cout << boss_name << "이 " << m_cPlayerStat->Name << "에게 " ;
	cout << condition << "상태이상을 걸었다!" << endl;
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
