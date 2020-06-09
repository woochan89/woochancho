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
		return "정상";
	else if (condition == POSION)
		return "중독";
	else 
		return "수면";
}


void Player::notify(string boss_name,Condition condition)
{
	cout << boss_name << "이 " << m_PlayerStat->Name << "에게 " ;
	cout << ReturnCondition(condition) << "상태이상을 걸었다!" << endl;
}

void Player::GetExp(int exp)
{
	int maxExp = 10 + (m_PlayerStat->Lv) * 2;
	int remainExp;

	cout << exp << "의 경험치를 획득하였습니다\n";
	if (m_Exp + exp >= maxExp)
	{
		remainExp = m_Exp + exp - maxExp;
		cout << "레벨업!\n";
		LVup();
	}
	m_Exp += exp;
	(*m_Skill.begin())->GetSkill()->GetLevel;

	if (m_PlayerStat->Lv == (*m_TmpSkill.begin())->GetSkill()->GetLevel)
	{
		m_Skill.push_back(m_TmpSkill.front());
		cout << "새로운 스킬 " << m_TmpSkill.front()->GetSkill()->Name << "을 배웠습니다!\n";
		m_TmpSkill.pop_front();
	}

	system("pause");
}


Player::~Player()
{
}




void Warrior::LVup()
{
	m_PlayerStat->Lv++;
	m_PlayerStat->Atk += 2;
	m_PlayerStat->Def += 2;
	m_PlayerStat->MaxHp += 5;
	m_PlayerStat->MaxMp += 2;
	m_PlayerStat->Hp = m_PlayerStat->MaxHp;
	m_PlayerStat->Mp = m_PlayerStat->MaxMp;
	m_Exp = 0;
}


void Rogue::LVup()
{
	m_PlayerStat->Lv++;
	m_PlayerStat->Atk += 3;
	m_PlayerStat->Def += 2;
	m_PlayerStat->MaxHp += 3;
	m_PlayerStat->MaxMp += 2;
	m_PlayerStat->Hp = m_PlayerStat->MaxHp;
	m_PlayerStat->Mp = m_PlayerStat->MaxMp;
	m_Exp = 0;
}


void Hunter::LVup()
{
	m_PlayerStat->Lv++;
	m_PlayerStat->Atk += 3;
	m_PlayerStat->Def += 1;
	m_PlayerStat->MaxHp += 2;
	m_PlayerStat->MaxMp += 2;
	m_PlayerStat->Hp = m_PlayerStat->MaxHp;
	m_PlayerStat->Mp = m_PlayerStat->MaxMp;
	m_Exp = 0;
}


void Priest::LVup()
{
	m_PlayerStat->Lv++;
	m_PlayerStat->Atk += 2;
	m_PlayerStat->Def += 1;
	m_PlayerStat->MaxHp += 3;
	m_PlayerStat->MaxMp += 4;
	m_PlayerStat->Hp = m_PlayerStat->MaxHp;
	m_PlayerStat->Mp = m_PlayerStat->MaxMp;
	m_Exp = 0;
}


void Magician::LVup()
{
	m_PlayerStat->Lv++;
	m_PlayerStat->Atk += 1;
	m_PlayerStat->Def += 1;
	m_PlayerStat->MaxHp += 2;
	m_PlayerStat->MaxMp += 5;
	m_PlayerStat->Hp = m_PlayerStat->MaxHp;
	m_PlayerStat->Mp = m_PlayerStat->MaxMp;
	m_Exp = 0;
}

