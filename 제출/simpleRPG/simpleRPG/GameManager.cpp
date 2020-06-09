#include "GameManager.h"

ObjectStat* MakeStat(string name, int atk = 0, int def = 0, int hp = 0, int mp = 0)
{
	ObjectStat* tmp = new ObjectStat();
	tmp->Name = name;
	tmp->Atk = atk;
	tmp->Def = def;
	tmp->Hp = hp;
	tmp->Mp = mp;
	return tmp;
}

GameManager::GameManager()
{
	Item* item1 = new Weapon("롱소드", 3, 0, 0, 0);
	Item* item2 = new Armor("레더아머", 0, 2, 0, 0);
	Item* item3 = new Accessory("구리반지", 0, 0, 3, 3);

	m_Shop.WeaponList.push_back(item1);
	m_Shop.ArmorList.push_back(item2);
	m_Shop.AccessoryList.push_back(item3);
}


void GameManager::showMain(Player* player)
{
	int sel;
	m_Player = player;
	while (true)
	{
		system("cls");
		cout << "1. 던전으로" << endl;
		cout << "2. 상태창" << endl;
		cout << "3. 인벤토리" << endl;
		cout << "4. 상점" << endl;
		cout << "5. 여관" << endl;
		cout << "6. 종료" << endl;
		cin >> sel;
		switch (sel)
		{
		case 1:
			if (m_Player->m_PlayerStat->Hp <= 0)
			{
				cout << " " << m_Player->m_PlayerStat->Name << "은 기절했습니다!\n";
				system("pause");
			}
			else
				dungeon(0);
			break;
		case 2:
			showStat();
			break;
		case 3:
			system("cls");
			showInventory(m_Player->m_Inventory);
			if (m_Player->m_Inventory.size() == 0)
				break;
			cout << "    나가기\n";
			sel = Draw::GetInstance()->Cursor(m_Player->m_Inventory.size() + 1, 0, 2);
			if (sel == m_Player->m_Inventory.size()+1)
				break;
			wearEquipment(m_Player->m_Inventory, sel);
			break;
		case 4:
			Shop();
			break;
		case 5:
			cout << " 여관에서 푹 쉬었습니다!\n";
			m_Player->m_PlayerStat->Hp = m_Player->m_PlayerStat->MaxHp;
			m_Player->m_PlayerStat->Mp = m_Player->m_PlayerStat->MaxMp;
			system("pause");
			break;
		case 6:
			return;
		}
	}
}

void GameManager::dungeon(int num)
{
	Monster* monster1 = new Monster(MakeStat("슬라임",2,0,10,4),1);	//몬스터 데이터 불러오기
	MonsterSkill* monsterskill1 = new MonsterSkill("독침", POSION, 1.2, 0, 2, ONE_ENEMY);
	monster1->m_Skill = monsterskill1;

	monster1->AddObserver(m_Player);//옵저버 등록

	battle(monster1);

	monster1->RemoveObserver(m_Player);//옵저버 해제
	delete monsterskill1;
	delete monster1;

}

void GameManager::battle(Monster* monster)
{
	int sel;
	ObjectSkill* tmpskill;
	ObjectStat PlayerStat = *m_Player->m_PlayerStat;
	ObjectStat MonsterStat = *monster->m_Monster;

	int playerDmg;
	float PlayerConditionDmg;
	int monsterdmg;
	while (PlayerStat.Hp != 0 && MonsterStat.Hp != 0)
	{
		playerDmg = 0;
		monsterdmg = 0;
		PlayerConditionDmg = 0;
		tmpskill = NULL;
		Draw::GetInstance()->drawBattleInterface(m_Player->m_PlayerStat, monster->m_Monster);
		Draw::GetInstance()->gotoxy(0, 15);
		switch (m_Player->m_Condition)//상태이상시 공격 및 도망 제한
		{
		case SLEEP:
			cout << m_Player->m_PlayerStat->Name << "은 수면 상태입니다!\n";
			system("pause");
			break;
		case POSION:
			PlayerConditionDmg = 0.1;
		case NOMAL:
			cout << "   1. 공격\n";
			cout << "   2. 스킬사용\n";
			cout << "   3. 도망\n";
			cin >> sel;
			switch (sel)
			{
			case 1:
				playerDmg = (m_Player->m_PlayerStat->Atk) - (monster->m_Monster->Def);
				break;
			case 2:
				while (true)
				{
					Draw::GetInstance()->gotoxy(0, 20);
					Draw::GetInstance()->showSkill(m_Player->m_Skill);
					cout << "돌아가기\n";
					sel = Draw::GetInstance()->Cursor(m_Player->m_Skill.size() + 1);
					if (sel == m_Player->m_Skill.size() + 1)
						break;
					tmpskill = m_Player->m_Skill.at(sel)->GetSkill();
					if (tmpskill->MpConsumtion > m_Player->m_PlayerStat->Mp)
					{
						cout << "마나가 부족합니다!\n";
						system("pause");
						continue;
					}
					playerDmg = tmpskill->Dmg;
					m_Player->m_PlayerStat->Mp -= tmpskill->MpConsumtion;
					break;
				}
				break;
			case 3:
				return;

			}

			monster->m_Monster->Hp -= playerDmg;//플레이어 공격
			if (monster->m_Monster->Hp < 0)
				monster->m_Monster->Hp = 0;
			Draw::GetInstance()->gotoxy(0, BASELINE);
			if (tmpskill == NULL)
				cout << " " << m_Player->m_PlayerStat->Name << "의 공격!\n";
			else
				cout << " " << m_Player->m_PlayerStat->Name << "의 " << tmpskill->Name << "!\n";
			cout << " " << m_Player->m_PlayerStat->Name << "이 " << monster->m_Monster->Name << "에게 " << playerDmg << " 의 데미지를 입혔습니다!\n";

			break;

		}


		Draw::GetInstance()->drawBattleInterface(m_Player->m_PlayerStat, monster->m_Monster);
		system("pause");

		//쇼스텟

		if (monster->m_Monster->Hp <= 0)//승리체크
		{
			cout << "승리!" << endl;
			m_Player->GetExp(monster->m_Exp);
			system("pause");
			break;
		}



		if (monster->m_skillpercent > rand() % 10&&tmpskill->MpConsumtion<=monster->m_Monster->Mp)//몬스터 공격
		{
			tmpskill = monster->m_Skill->GetSkill();
			monsterdmg = tmpskill->Dmg;
			monster->m_Monster->Mp -= tmpskill->MpConsumtion;
			cout << " " << monster->m_Monster->Name << "의 " << tmpskill->Name << "!\n";
			if (tmpskill->condition != NOMAL)
				monster->Notification();
		}
		else
		{
			monsterdmg = monster->m_Monster->Atk;
			cout << " " << monster->m_Monster->Name << "의 공격!\n";
		}
		cout << " " << monster->m_Monster->Name << "이 " << m_Player->m_PlayerStat->Name << "에게 " << monsterdmg << " 의 데미지를 입혔습니다!\n";
		if (PlayerConditionDmg != 0)
			cout << " " << m_Player->m_PlayerStat->Name << "이 독 데미지를 입었습니다!\n";
		m_Player->m_PlayerStat->Hp -= (monsterdmg+m_Player->m_PlayerStat->MaxHp*PlayerConditionDmg);

		if (m_Player->m_PlayerStat->Hp < 0)
			m_Player->m_PlayerStat->Hp = 0;
		Draw::GetInstance()->drawBattleInterface(m_Player->m_PlayerStat, monster->m_Monster);
		system("pause");

		if (m_Player->m_PlayerStat->Hp <= 0)//패배체크
		{
			cout << " " << m_Player->m_PlayerStat->Name <<"가 기절했습니다!\n";
			system("pause");
			break;
		}
	}
}


void GameManager::showStat()
{
	Draw::GetInstance()->showStat(m_Player->m_PlayerStat);

	cout << "\n장비창" << endl;
	cout << "무기 : " ;
	if(m_Player->m_Weapon!=NULL)
	Draw::GetInstance()->showEquipment(m_Player->m_Weapon->GetName(), m_Player->m_Weapon->GetAtk(), m_Player->m_Weapon->GetDef(), m_Player->m_Weapon->GetHp(), m_Player->m_Weapon->GetMp());
	cout << "\n방어구 : " ;
	if(m_Player->m_Armor!=NULL)
	Draw::GetInstance()->showEquipment(m_Player->m_Armor->GetName(), m_Player->m_Armor->GetAtk(), m_Player->m_Armor->GetDef(), m_Player->m_Armor->GetHp(), m_Player->m_Armor->GetMp());
	cout << "\n장신구 : " ;
	if(m_Player->m_Accessory !=NULL)
	Draw::GetInstance()->showEquipment(m_Player->m_Accessory->GetName(), m_Player->m_Accessory->GetAtk(), m_Player->m_Accessory->GetDef(), m_Player->m_Accessory->GetHp(), m_Player->m_Accessory->GetMp());
	
	cout << "\n\n보유스킬" << endl;
	Draw::GetInstance()->showSkill(m_Player->m_Skill);
	system("pause");
}

void GameManager::showInventory(list<Item*> Target,string name)
{
	if (Target.size() == 0)
	{
		cout << "소지한 아이템이 없습니다\n";
		system("pause");
		return;
	}
	list<Item*>::iterator iter=Target.begin();
	cout << name << endl << endl;
	while (iter != Target.end())
	{
		cout << "   ";
		Draw::GetInstance()->showEquipment((*iter)->GetName(), (*iter)->GetAtk(), (*iter)->GetDef(), (*iter)->GetHp(), (*iter)->GetMp());
		cout << "\n";
		iter++;
	}

}

void GameManager::Shop()
{
	int sel;
	while (true)
	{
		system("cls");
		cout << "1. 무기" << endl;
		cout << "2. 방어구" << endl;
		cout << "3. 소모품" << endl;
		cout << "4. 나가기" << endl;
		cin >> sel;
		system("cls");
		switch (sel)
		{
		case 1:
			if (m_Shop.WeaponList.size() == 0)
			{
				cout << "매진\n";
				system("pause");
			}
			else
			{
				showInventory(m_Shop.WeaponList, "무기");
				cout << "\n   나가기\n";
				sel = Draw::GetInstance()->Cursor(m_Shop.GetWeaponMax()+1,0,2);
				if (sel == m_Shop.GetWeaponMax() + 1)
					continue;
				buySomething(&m_Shop.WeaponList, &m_Player->m_Inventory, sel);
			}
			break;
		case 2:
			if (m_Shop.ArmorList.size() == 0)
			{
				cout << "매진\n";
				system("pause");
			}
			else
			{
				showInventory(m_Shop.ArmorList, "방어구");
				cout << "\n   나가기\n";
				sel = Draw::GetInstance()->Cursor(m_Shop.GetArmorMax()+1, 0, 2);
				if (sel == m_Shop.GetArmorMax() + 1)
					continue;

				buySomething(&m_Shop.ArmorList, &m_Player->m_Inventory, sel);
			}
			break;
		case 3:
			if (m_Shop.AccessoryList.size() == 0)
			{
				cout << "매진\n";
				system("pause");
			}
			else
			{
				showInventory(m_Shop.AccessoryList, "장신구");
				cout << "\n   나가기\n";
				sel = Draw::GetInstance()->Cursor(m_Shop.GetAccessoryMax()+1, 0, 2);
				if (sel == m_Shop.GetAccessoryMax() + 1)
					continue;
				buySomething(&m_Shop.AccessoryList, &m_Player->m_Inventory, sel);
			}
			break;
		case 4:
			Draw::GetInstance()->drawText("방문해 주셔서 감사합니다!");
			system("pause");
			return;
		}
	}
}

void GameManager::wearEquipment(list<Item*> &inventory, int target)
{
	list<Item*>::iterator iter = inventory.begin();
	for (int i = 1; i < target; i++)
		iter++;
	Item* tmp = *iter;

	if (tmp->GetType() == WEAPON)
	{
		if (m_Player->m_Weapon != NULL)
			offEquipment(WEAPON);
		m_Player->m_Weapon = *iter;
		inventory.erase(iter);
	}
	else if (tmp->GetType() == ARMOR)
	{
		if (m_Player->m_Armor != NULL)
			offEquipment(ARMOR);
		m_Player->m_Armor = *iter;
		inventory.erase(iter);
	}
	else
	{
		if (m_Player->m_Accessory != NULL)
			offEquipment(ACCESSORY);
		m_Player->m_Accessory = *iter;
		inventory.erase(iter);
	}
	m_Player->m_PlayerStat->Atk += tmp->GetAtk();//스텟조정
	m_Player->m_PlayerStat->Def += tmp->GetDef();
	m_Player->m_PlayerStat->MaxHp += tmp->GetHp();
	m_Player->m_PlayerStat->MaxMp += tmp->GetMp();
	m_Player->m_PlayerStat->Hp += tmp->GetHp();
	m_Player->m_PlayerStat->Mp += tmp->GetMp();
}

void GameManager::offEquipment(ItemType type)
{
	Item* tmp;

	if (type == WEAPON)
	{
		m_Player->m_Inventory.push_back(m_Player->m_Weapon);
		tmp = m_Player->m_Armor;
		m_Player->m_Weapon = NULL;
	}
	else if (type == ARMOR)
	{
		m_Player->m_Inventory.push_back(m_Player->m_Armor);
		tmp = m_Player->m_Armor;
		m_Player->m_Armor = NULL;
	}
	else
	{
		m_Player->m_Inventory.push_back(m_Player->m_Accessory);
		tmp = m_Player->m_Accessory;
		m_Player->m_Accessory = NULL;
	}

	m_Player->m_PlayerStat->Atk -= tmp->GetAtk();//스텟조정
	m_Player->m_PlayerStat->Def -= tmp->GetDef();
	m_Player->m_PlayerStat->MaxHp -= tmp->GetHp();
	m_Player->m_PlayerStat->MaxMp -= tmp->GetMp();
	m_Player->m_PlayerStat->Hp -= tmp->GetHp();
	m_Player->m_PlayerStat->Mp -= tmp->GetMp();
	if (m_Player->m_PlayerStat->Hp < 0)
		m_Player->m_PlayerStat->Hp = 1;
	if (m_Player->m_PlayerStat->Mp < 0)
		m_Player->m_PlayerStat->Mp = 0;

	delete tmp;
}


void GameManager::buySomething(list<Item*> *fromlist, list<Item*> *tolist, int fromtarget)
{
	list<Item*>::iterator iter = fromlist->begin();
	for (int i = 1; i < fromtarget;i++)
		iter++;

	tolist->push_back(*iter);
	fromlist->erase(iter);
}


GameManager::~GameManager()
{

}
