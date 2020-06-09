#include"GameManager.h"



int main()
{
	AbstractFactory *playermanager;
	GameManager PlayGame;
	int Width = (WIDTH * 2) + 1;
	int Height = HEIGHT + 5;
	char buf[256];
	int sel;
	sprintf(buf, "mode con: lines=%d cols=%d", Height, Width);
	system(buf);
	string name;
	Player* player;

	cout << "����� �̸���?\n";
	cin >> name;

	while (true)
	{
		system("cls");
		cout << "������ �����ϼ���\n";
		cout << "1. ����\n";
		cout << "2. ����\n";
		cout << "3. ��ɲ�\n";
		cout << "4. ����\n";
		cout << "5. ������\n";
		cin >> sel;
		switch (sel)
		{
		case 1:
			player = new Warrior();
			playermanager = new WarriorCharacter();
			break;
		case 2:
			player = new Rogue();
			playermanager = new RogueCharacter();
			break;
		case 3:
			player = new Hunter();
			playermanager = new HunterCharacter();
			break;
		case 4:
			player = new Priest();
			playermanager = new PriestCharacter();
			break;
		case 5:
			player = new Magician();
			playermanager = new MagicianCharacter();
			break;
		default:
			continue;
		}
		break;
	}
	player->m_PlayerStat = playermanager->makePlayer(name);
	player->m_Skill = playermanager->makeSkill();
	PlayGame.showMain(player);
	return 0;
}