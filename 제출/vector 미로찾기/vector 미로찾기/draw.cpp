#include"draw.h"



draw::draw()
{
}



void draw::drawmap(vector<status> map, int width, int height)
{
	vector<status>::iterator iter = map.begin();
	for (int i=0; iter != map.end(); iter++,i++)
	{
		if (i%width == 0&&i!=0)
			cout << "\n";
		drawsupport(*iter);
	}
}

void draw::drawsupport(status stat)
{
	if (stat == status::empty)
		cout << "  ";
	else if (stat == status::wall)
		cout << "бс";
	else if (stat == status::player)
		cout << "б┌";

}


draw::~draw()
{
}
