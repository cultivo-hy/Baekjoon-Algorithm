#pragma warning(disable:4996)
#include <cstdio>
#include <queue>
#include <fstream>
#include <sstream>
#include <cstring>

#define MUL(i,j,k) list[0][i] * list[1][j] * list[2][k]
int list[3][102], N;
int dp[101][101][101];
int aIndex[3];

using namespace std;
int main(){
	ifstream inStream("board.inp");
	ofstream outStream("board.out");
	
	for (int i = 0; i < 3; i++){
		inStream >> aIndex[i];
		int N = aIndex[i];
		for (int j = 1; j <= N; j++){
			inStream >>  list[i][j];
		}
	}
	int  x = aIndex[0], y = aIndex[1], z = aIndex[2];
	for (int i = 1; i <= x; i++){
		for (int j = 1; j <= y; j++){
			for (int k = 1; k <= z; k++){
				dp[i][j][k] = max(dp[i][j][k - 1], max(dp[i][j - 1][k], max(dp[i][j - 1][k - 1], max(dp[i - 1][j][k],
					max(dp[i - 1][j][k - 1], max(dp[i - 1][j - 1][k], dp[i - 1][j - 1][k - 1] + MUL(i, j, k)))))));
			}
		}
	}
	outStream << dp[x][y][z];	
}