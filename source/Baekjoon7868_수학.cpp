#include <iostream>

using namespace std;
long long prime_1, prime_2, prime_3;

bool mod(int number) {
	bool value = false;
	if (number % prime_1 == 0 || number %prime_2 == 0 || number % prime_3 == 0)	{
		value = true;
	}
	return value;
}

int main()
{
	cin >> prime_1 >> prime_2 >> prime_3;
	int index, count = 0;
	cin >> index;
	long long * list = new long long[index];
	long long start = prime_1;
	while (count < index) {
		if (mod(start)) { 
			list[count] = start;
			count++;
		}
		start++;
	}
	for (int i = 0; i < index; i++)
		cout << list[i] << " ";
}