#include "Player.h"




Player::Player(ObjectStat *stat):m_cPlayerStat(stat),alarmState(true)
{
}

void Player::notify(string boss_name)
{
	cout << m_cPlayerStat->Name << "���� �˸�" << endl;
	cout << boss_name << "����!" << endl;
}

Player::~Player()
{
}
