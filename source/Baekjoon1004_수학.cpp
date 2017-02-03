#include <iostream>
#include <cmath>
using namespace std;
class Circle{
private:
	double x, y, r;
public:
	Circle(double x = 0, double y = 0, double r = 0)
	{
		this->x = x;
		this->y = y;
		this->r = r;
	}
	bool isInitPoint(double x1, double y1, double x2, double y2)
	{
		bool value = false;
		double distance1 = sqrt((this->x - x1)*(this->x - x1) + (this->y - y1)*(this->y - y1));
		double distance2 = sqrt((this->x - x2)*(this->x - x2) + (this->y - y2)*(this->y - y2));

		if ((distance1 < r && distance2 > r) || (distance1 > r && distance2 < r))
			value = true;
		else
			value = false;
		return value;
	}
};
int main()
{
	int getDataCase;
	cin >> getDataCase;
	int* resultArray = new int[getDataCase];
	for (int i = 0; i < getDataCase; i++)
	{
		double x1, y1, x2, y2 = 0;
		resultArray[i] = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		int planetCount = 0;
		cin >> planetCount;
		for (int j = 0; j < planetCount; j++)
		{
			double xPlanet, yPlanet, radius = 0;
			cin >> xPlanet >> yPlanet >> radius;
			Circle c(xPlanet, yPlanet, radius);
			if (c.isInitPoint(x1, y1, x2, y2))
			{
				resultArray[i]++;
			}
		}
	}
	for (int i = 0; i < getDataCase; i++)
	{
		cout << resultArray[i] << endl;
	}
}