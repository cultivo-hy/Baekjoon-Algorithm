#include <iostream>

using namespace std;

int main(){
	int num1, num2, num3;
	while (true)
	{
		cin >> num1 >> num2 >> num3;
		if (	num1 == 0 && num2 == 0 && num3 == 0) {
			break;
		}
		else if ( num2 * 2 == num1 + num3) { 
			cout << "AP" << endl;
		}
		else if (num2*num2 == num1 * num3)
		{
			cout << "GP" << endl;
		}
		else
		{
			break;
		}
	}
}