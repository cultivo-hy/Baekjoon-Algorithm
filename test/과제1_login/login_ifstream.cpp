/*Baekjoon 2���� �迭 ������ ����,
2016.08.29 inStream ����,
DP�� Ǯ��.
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int S[1001][1001];
using namespace std;

int main(){
	ifstream inStream("login.inp");
	ofstream outStream("login.out");
	int iL = 0, iR = 0, value = 0, count = 0;
	inStream >> iL;
	inStream >> iR;
	for (int i = 1; i <= iL; i++){
		for (int j = 1; j <= iR; j++){
			inStream >> value;
			S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + value;
		}
	}
	inStream >> count;
	for (int i = 0; i < count; i++){
		int x1, x2, y1, y2;
		inStream >> y1 >> y2 >> x1 >> x2;
		outStream << S[x2][y2] - S[x2][y1 - 1] - S[x1 - 1][y2] + S[x1 - 1][y1 - 1] << endl;
	}
}
