#include "Player.h"




Player::Player(ObjectStat *stat):m_cPlayerStat(stat),alarmState(true)
{
}

void Player::notify(string boss_name)
{
	cout << m_cPlayerStat->Name << "에게 알림" << endl;
	cout << boss_name << "출현!" << endl;
}

Player::~Player()
{
}
