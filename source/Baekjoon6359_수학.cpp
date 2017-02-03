#include <iostream>

using namespace std;

int main()
{
	int dataCase;
	cin >> dataCase;
	int* resultArray = new int[dataCase];
	for (int i = 0; i < dataCase; i++) {
		int roomCount;
		cin >> roomCount;
		int* numberArray = new int[roomCount];
		for (int i = 0; i < roomCount; i++) 
			numberArray[i] = i + 1;
		for (int i = 0; i < roomCount; i++) {
			int num = numberArray[i];
			int count = 0;
			for (int j = 0; j < num; j++) {
				if (num % (j + 1) == 0)
					count++;
			}
			numberArray[i] = count;
		}
		int count = 0;
		for (int i = 0; i < roomCount; i++) {
			if (numberArray[i] % 2 == 1)
				count++;
		}
		resultArray[i] = count;
	}
	for (int i = 0; i < dataCase; i++)  
		cout << resultArray[i]<<endl;
}