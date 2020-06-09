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

	cout << "당신의 이름은?\n";
	cin >> name;

	while (true)
	{
		system("cls");
		cout << "직업을 선택하세요\n";
		cout << "1. 전사\n";
		cout << "2. 도적\n";
		cout << "3. 사냥꾼\n";
		cout << "4. 사제\n";
		cout << "5. 마법사\n";
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