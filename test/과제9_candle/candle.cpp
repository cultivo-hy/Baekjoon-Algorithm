#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

int N, dList[27][27], C, value;
int arr[27];
char list[3], ch, tmpCh;
string tmp;
istream& getline(istream& is, string& str);
int main(){
	memset(dList, 1, sizeof(dList));
	ifstream inStream("candle.inp");
	ofstream outStream("candle.out");
	inStream >> N;
	inStream >> list[0] >> list[1] >> list[2];
	for (int i = 0; i < N; i++){
		inStream >> ch >> C;
		int indexX = ch - 'a';
		arr[indexX] = C;
		for (int i = 0; i < C; i++){
			inStream >> tmpCh >> value;
			int indexY = tmpCh - 'a';
			dList[indexX][indexY] = value;
		}
		dList[i][i] = 0;
	}
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			for (int k = 0; k < N; k++){
				if (dList[k][j] > dList[k][i] + dList[i][j] + arr[i]) {
					dList[k][j] = dList[k][i] + dList[i][j] + arr[i];
				}
			}
		}
	}
	int a = list[0] - 'a', b = list[1] - 'a', c = list[2] - 'a';
	int minV = 987654321, ind = 0;
	for (int i = 0; i < N; i++){
		int comp = max(dList[i][a], max(dList[i][b], dList[i][c]));
		if (minV > comp){
			minV = max(dList[i][a], max(dList[i][b], dList[i][c]));
			ind = i;
		}
	}
	char ch = (char)('a' + ind);
	outStream << ch << " " << minV;
}