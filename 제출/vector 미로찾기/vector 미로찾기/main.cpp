#include"draw.h"
#define WIDTH 10
#define HEIGHT 10


void main()
{
	draw drawmanager;
	vector<status> map(WIDTH*HEIGHT, status::empty);
	int player[2] = { 1, 1 };

	vector<status>::iterator iter=map.begin();

	for (int i = 0; i < WIDTH*HEIGHT; i++)//외벽 만들=기
	{
		if (i <= WIDTH || i % WIDTH == 0 
			|| i % WIDTH == WIDTH - 1 || i > WIDTH*HEIGHT - WIDTH)
			map[i] = status::wall;
	}
	
	map[player[1] * WIDTH + player[0]] = status::player;

	drawmanager.drawmap(map, WIDTH, HEIGHT);



}