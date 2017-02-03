#include <iostream>
#include <algorithm>

using namespace std;

class Point {
private:
	double x, y;
public:
	Point( double x=0, double y=0 ) {
		this->x = x;
		this->y = y;
	}
	double getPointX() {
		return x;
	}
	double getPointY() {
		return y;
	}
};
int main()
{
	int buildingCount;
	cin >> buildingCount;
	int* buildingHeight = new int[buildingCount];
	for ( int i = 0; i < buildingCount; i++ ) {
		double height;
		cin >> height;
		buildingHeight[i] = height;
	}
	Point* buildingHouse = new Point[buildingCount]();
	for ( int i = 0; i < buildingCount; i++ ) {
		Point t(i+1, buildingHeight[i]);
		buildingHouse[i] = t;
	}
	for ( int i = 0; i < buildingCount; i++ ) {
		Point start = buildingHouse[i];
		double slope = 0;
		int count = 0;
		for ( int j = 0; j < buildingCount; j++ ) {			
			int temp = j;
			bool flag = true;
			Point tmp = buildingHouse[temp];
			if (i == j)   continue;	
			else if (i > j) {	// left 老 版快
				while (temp <i) {
				    tmp = buildingHouse[temp];
					if (temp == j)
						slope = (start.getPointY() - tmp.getPointY()) / (start.getPointX() - tmp.getPointX());
					else {
						if (slope < (start.getPointY() - tmp.getPointY()) / (start.getPointX() - tmp.getPointX()))
							flag *= true;
						else
							flag *= false;
					}		
					temp++;
				}
			}
			else {					// right 老 版快
				while (temp > i) {
				    tmp = buildingHouse[temp];
					if (temp == j)
						slope = ( start.getPointY() - tmp.getPointY() ) / ( start.getPointX() - tmp.getPointX() );
					else {
						if (slope > ( start.getPointY() - tmp.getPointY() ) / ( start.getPointX() - tmp.getPointX())  )
							flag *= true;
						else
							flag *= false;
					}
					temp--;
				}
			}
			if ( flag == true )  count++;
		}
		buildingHeight[i] = count;
		cout << buildingHeight[i] << endl;
	}
	sort(buildingHeight, buildingHeight + buildingCount);
	cout << buildingHeight[buildingCount-1];
}