#include <iostream>

using namespace std;
// time 오래 걸리는거 생각해보기
int main()
{
	int col, row;
	cin >> col >> row;
	long** array = new long*[col];
	for (int i = 0; i < col; i++) {
		array[i] = new long[row];
		for (int j = 0; j < row; j++) {
			long data;
			cin >> data;
			array[i][j] = data;
		}
	}
	int count;
	cin >> count;
	long* dataArray = new long[count];
	for (int i = 0; i < count; i++) {
		long data = 0;
		int col1, row1, col2, row2;
		cin >> col1 >> row1 >> col2 >> row2;
		for (int i = col1-1; i <col2; i++) {
			for (int j = row1-1; j < row2; j++) {
				data += array[i][j];
			}
		}
		dataArray[i] = data;
	}
	for (int i = 0; i < count; i++)
	{
		cout << dataArray[i] << endl;
	}
}