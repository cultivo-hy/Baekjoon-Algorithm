#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
typedef long long ll;
using namespace std;
int list[101];
ll dp[101][10010];          //  X  ��� = Y �� ���ؼ� ���� �� �ִ�

int main(){
	int result;
	int cnt;
	cin >> cnt >> result;
	for (int i = 1; i <= cnt; i++){
		scanf("%d", &list[i]);	// coinList
		dp[i][list[i]] = 1;
	}
	for (int i = 1; i <= cnt; i++){
		for (int j = 1; j <= result; j++){
			dp[i][j] = dp[i][j] + dp[i - 1][j] + ((j - list[i] >= 0) ? dp[i][j - list[i]] : 0);
		}
	}
	cout << ((dp[cnt][result] != 0) ? dp[cnt][result] : -1) << endl;
}