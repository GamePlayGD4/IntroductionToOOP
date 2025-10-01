#include <iostream>
using namespace std;

struct Point
{
	double x;
	double y;
};

void main()
{
	setlocale(LC_ALL, "");
	cout << "Hello OOP" << endl;
	Point A;
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;
}