#include <iostream>

using namespace std;
int size[10] = { 1, 4, 4, 2, 1, 1, 4, 4, 2, 1 };
int main()
{ 
	int dataCase;
	cin >> dataCase;
	int num, pow;
	for (int i = 0; i < dataCase; i++)
	{ 
		cin >> num >> pow;
		int value = num % 10;
		if (value == 0) value = 10;
		int index = size[value - 1];
		int tmp = pow % index;
		if (tmp == 0) tmp = index;
		int result = 1;
		for (int j = 0; j < tmp; j++)
			result *= value;
		if (result%10 == 0) cout << 10 << endl;
		else cout << result % 10 << endl;
	}
}