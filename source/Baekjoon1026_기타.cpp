#include <iostream>
#include <algorithm>
using namespace std;

bool myfunction(int i, int j) { return (i>j); }
int main()
{
	int arraySize;
	cin >> arraySize;
	int* arrayA = new int[arraySize];
	int* arrayB = new int[arraySize];
	int getData = 0;
	for (int i = 0; i < arraySize; i++)
	{
		cin >> getData;
		arrayA[i] = getData;
	}
	for (int i = 0; i < arraySize; i++)
	{		
		cin >> getData;
		arrayB[i] = getData;
	}
	sort(arrayA,arrayA+arraySize);
	sort(arrayB, arrayB + arraySize, myfunction);
	int result=0;
	for (int i = 0; i < arraySize; i++)
	{
		result += arrayB[i] * arrayA[i];
	}
	cout << result;
}