#include <cstdio>
#include <queue>
using namespace std;

int S[1002];
int dp[1002];
int main(){
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d", &S[i]);
	}
	dp[1] = S[0];
	for (int i = 2; i <= N; i++){
		int sum = 0;
		int index = (i / 2);
		for (int j = 1; j <= index; j++){
			sum = max(sum, dp[j] + dp[i - j]);
		}
		dp[i] = max(S[i - 1], sum);
	}
	printf("%d", dp[N]);
}
