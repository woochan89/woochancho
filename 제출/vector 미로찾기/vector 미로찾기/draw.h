#pragma once
#include<iostream>
#include<vector>
using namespace std;


enum status
{
	empty=1,
	wall,
	player
};


class draw
{
public:
	void drawmap(vector<status> map,int width,int height);
	void drawsupport(status stat);

	draw();
	~draw();
};

