#include "Main.h"

Main::Main()
{
}

void Main::maketower(int stonemax,int *tower[])
{
	for (int i = 0; i < TOWERMAX; i++)
	{
		tower[i] = new int[stonemax];
	}

	for (int i = 0; i < TOWERMAX; i++)
	{
		for (int j = 0; j < stonemax; j++)
		{
			if (i == 0)
				tower[i][j] = stonemax - j;
			else
				tower[i][j] = 0;
		}
	}

}

Main::~Main()
{
}
