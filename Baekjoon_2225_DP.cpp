#include <cstdio>
int dp[201], N, K;
int main(){
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= K; i++)	 dp[i] = i;
	for (int i = 1; i < N; i++){
		for (int j = 1; j <= K; j++)
			dp[j] = (dp[j] + dp[j - 1]) % 1000000000;
	}
	printf("%d", dp[K] % 1000000000);
}
