#include <iostream>

using namespace std;
int array[41] = { 0, 1 };

int fibonacci(int n) {
	if (array[n] == 0 && n != 0)
	{
		array[n] = fibonacci(n - 1) + fibonacci(n - 2);
	}	
	return array[n];
}

int main()
{
	int testCase;
	cin >> testCase;
	int* inputArray = new int[testCase];
	for (int i= 0; i < testCase; i++)
	{
		int inputData = 0;
		cin >> inputData;
		fibonacci(inputData);
		inputArray[i] = inputData;
	}
	for (int i = 0; i < testCase; i++)
	{
		if (inputArray[i] != 0)
			cout << array[inputArray[i] - 1] << " " << array[inputArray[i]] << endl;
		else
			cout << 1 << " " << 0 << endl;
	}
}