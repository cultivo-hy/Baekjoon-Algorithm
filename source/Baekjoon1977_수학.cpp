#include <iostream>
#include <cmath>

using namespace std;
int main()
{
	int minValue, maxValue;
	cin >> minValue >> maxValue;
	int startIndex = sqrt(minValue);
	int endIndex = sqrt(maxValue);
	if (startIndex > endIndex)
		cout << -1 << endl;
	else {
		if (startIndex == endIndex) {
			if (minValue == maxValue) {
				if (startIndex * startIndex == minValue)
					cout << minValue << endl << minValue << endl;
				else
					cout << -1<< endl;
			}
			else if (startIndex * startIndex == minValue) {
				cout << minValue << endl << minValue << endl; 
			}
			else
				cout << -1 << endl;
		}
		else {
			int i = 0;
			if (startIndex * startIndex == minValue)
				i = startIndex;
			else
				i = startIndex + 1;
			int sum = 0;
			int start = i;
			for ( ; i <= endIndex; i++) {
				sum += i*i;
			}
			cout << sum << endl << start*start << endl;
		}
	}
}
