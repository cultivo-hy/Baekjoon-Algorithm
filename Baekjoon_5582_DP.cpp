#include <iostream>
#include <cstdio>
#include <string>
#define max(a,b) (a>b) ? a : b
using namespace std;
string T1, T2;
int dp[4001][4001],maxV;
int main(){
	cin >> T1 >> T2;
	int s1 = T1.size(), s2 = T2.size();
	for (int i = 1; i <= s1; i++){
		for (int j = 1; j <= s2 ; j++){
			dp[i][j] = (T1[i - 1] == T2[j- 1]) ? dp[i - 1][j - 1] + 1 : 0;
			maxV = max(maxV, dp[i][j]);
		}	
	}
	printf("%d", maxV);
}
