#pragma warning(disable:4996)
#include <cstdio>
#include <queue>
using namespace std;
int S[310];
int dp[310];
int main(){
	int cnt;
	scanf("%d", &cnt);
	for (int i = 1; i <= cnt; i++){
		scanf("%d", &S[i]);
	}
	dp[1] = S[1];
	dp[2] = S[1] + S[2];
	dp[3] = max(S[1] + S[3], S[2] + S[3]);
	for (int i = 4; i <= cnt; i++){
		dp[i] = S[i] + max(dp[i - 2], dp[i - 3] + S[i - 1]);
	}
	printf("%d", dp[cnt]);
}

