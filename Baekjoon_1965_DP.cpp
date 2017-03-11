#include <cstdio>
#include <queue>
int N, L[1001];
int DP[1001];
int maxV;
int main(){
	int i, j;						
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
		scanf("%d", &L[i]);
	for ( i = 1; i <= N; i++){
		for ( j = 1, DP[i] = 1; j < i; j++){
			if (L[i] > L[j] && DP[i] < DP[j] + 1)	DP[i] = DP[j] + 1;
		}
		maxV = std::max(maxV, DP[i]);
	}
	printf("%d", maxV);
}
