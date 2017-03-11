#pragma warning(disable:4996)
#include <cstdio>
#include <climits>
#include <queue>
#include <algorithm>
using namespace std;
int dp[100001];

int main(){
	int N,T; 
	scanf("%d", &N);
	dp[0] = INT_MIN/200;
	for (int i = 1; i <= N; i++){
		scanf("%d", &T);
		dp[i] = max(dp[i-1] + T, T);
	}
	sort(dp, dp + N+1);
	printf("%d", dp[N]);
}
