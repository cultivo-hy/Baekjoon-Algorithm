#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n; 
	int* array = new int[n];
	for (int i = 0; i < n; i++) cin >> array[i];
	sort(array, array + n);
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			num += array[j];
		}
	}
	cout << num;
}