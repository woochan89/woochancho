#include <iostream>
#include "Point.h"
#include "Distance.h"
using namespace std;

void main()
{
	Point a = { 0, 0 };
	Point b = { 3, 4 };

	double dist_a_b = Distance(a, b);

	cout << "(" << a.x << ", " << a.y << ") �� ";
	cout << "(" << b.x << ", " << b.y << ") �� �Ÿ� = " << dist_a_b << endl;

	return;
}