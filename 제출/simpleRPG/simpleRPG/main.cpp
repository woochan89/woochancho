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





	Warrior* player1 = new Warrior();
	playermanager = new WarriorCharacter();
	player1->m_PlayerStat = playermanager->makePlayer("¿ìÂù");
	player1->m_Skill.push_back(playermanager->makeSkill());
	PlayGame.showMain(player1);

	

	return 0;
}