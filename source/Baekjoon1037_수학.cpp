#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int dataCase;
	cin >> dataCase;
	long long* list = new long long[dataCase];
	for (int i = 0; i < dataCase; i++)
	{
		int value;
		cin >> value;
		list[i] = value;
	}
	sort(list, list + dataCase);
	long long result = 0;
	if (dataCase == 1)
		result = list[0] * list[0];
	else
	{
		result = list[0] * list[dataCase - 1];
	}
	cout << result;
}