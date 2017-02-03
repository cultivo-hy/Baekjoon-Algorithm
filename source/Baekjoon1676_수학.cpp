#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int inputData;
	cin >> inputData;
	int count = 0;
	vector<int> list;
	for (int i = 1; i <= inputData; i++)	{
		if (i % 5 == 0) 	list.push_back(i);
	}
	while (!list.empty()) {
		int data = list.at(list.size() - 1);
		while (true) {			
			if (data % 5 == 0) {
				data = data / 5;
				count++;
			}
			else break;
		}
		list.resize(list.size() - 1);
	}
	cout << count;
}