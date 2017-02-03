#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
typedef long long ll;
using namespace std;

int list[101];
ll dp[3][10010];

int main(){
	int result;
	int cnt;
	cin >> cnt >> result;
	for (int i = 1; i <= cnt; i++){
		scanf("%d", &list[i]);
	}
	dp[0][0] = 1;
	dp[1][0] = 1;
	for (int i = 1; i <= cnt; i++){
		for (int j = 1; j <= result; j++){
			dp[i % 2][j] = dp[(i + 1) % 2][j] + ((j - list[i] >= 0) ? dp[i % 2][j - list[i]] : 0);
		}
	}
	cout << ((dp[cnt % 2][result] != 0) ? dp[cnt % 2][result] : -1);
}
