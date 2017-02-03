#include <iostream>

using namespace std;
long long* dataArray = { 0 };
long long koong(int n)
{
	if (dataArray[n] == 0) {
		if (n == 2)  	     dataArray[2] = 2;
		else if (n == 3)  dataArray[3] = 4;
		else if (n < 2)   	 dataArray[n] = 1;
		else
			dataArray[n] = koong(n - 4) + koong(n - 3) + koong(n - 2) + koong(n - 1);
	}
	return dataArray[n];
}
int main()
{
	int dataCase;
	cin >> dataCase;
	long long* resultArray = new long long[dataCase];
	for (int i = 0; i < dataCase; i++) {
		int inputData;
		cin >> inputData;
		dataArray = new long long[inputData + 1];
		koong(inputData);
		resultArray[i] = dataArray[inputData];
	}
	for (int i = 0; i < dataCase; i++)
		cout << resultArray[i] << endl;
}