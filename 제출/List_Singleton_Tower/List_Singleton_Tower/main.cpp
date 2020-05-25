#include"Gamemanager.h"

void main()
{
	int select;
	Drawmanager draw;
	draw.DrawInterface(TOWER_MAX);
	while (true)
	{
		cin >> select;
		switch (select)
		{
		case 1:
			Gamemanager::GetInstance()->stacktower();
			break;

		case 2:
			Gamemanager::GetInstance()->removetower();
			break;

		case 3:
			return;
		}

	}
}