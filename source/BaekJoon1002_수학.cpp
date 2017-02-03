#include <iostream>
#include <cmath>
/*
  int 와 double 차이 !!!!!!
*/
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
	int findDot(const Circle& circle)
	{
		int dotCount = 0;
		// 두 이차방정식의 해를 찾는 것.
		double distance = sqrt((circle.getX() - x) * (circle.getX()- x) + (circle.getY()-y) * (circle.getY()-y));
		double radiusSum = circle.getR() + r;
		double radiusSubtraction = abs(circle.getR() - r);
		if (distance > radiusSum)
		{
			dotCount = 0;
		}
		else if (distance == radiusSum){
			dotCount = 1;
		}
		else
		{	
			// 겹치는 경우
			if (radiusSubtraction == 0 && distance == 0){
				dotCount = -1;
			}
			else{
				//교점 2개
				if (radiusSubtraction < distance){
 					dotCount = 2;
				}
				//교점 1개
				else if (radiusSubtraction == distance){
					dotCount = 1;
				}
				// inside;
				else{		
					dotCount = 0;
				}
			}
		}
		return dotCount;
	}
	double getX()	 const {
		return x;
	}
	double getY() const {
		return y;
	}
	double getR() const {
		return r;
	}
};
int main()
{
	// 원 두개 만든 후에 교점의 개수를 찾는 문제
	int dataCount;
	cin >> dataCount;
	int* array = new int[dataCount];
	for (int i = 0; i < dataCount; i++)
	{
		double x1, y1, r1, x2, y2, r2 =0;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		Circle c1(x1, y1, r1);
		Circle c2(x2, y2, r2);
		array[i] = c1.findDot(c2);
	}
	for (int i = 0; i < dataCount; i++)
	{
		cout << array[i] << endl;
	}
}
