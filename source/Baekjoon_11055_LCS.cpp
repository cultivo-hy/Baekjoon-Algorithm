#include <cstdio>
#include <queue>
int maxV, maxS, N, L[1001], DP[1001], S[1001];
int main(){
	int i, j;						
	scanf("%d", &N);
	for (i = 1; i <= N; i++)		scanf("%d", &L[i]);
	for (i = 1; i <= N; i++){
		S[i] = L[i];
		for (j = 1 ; j < i; j++){
			if (L[i] > L[j])			S[i] = std::max(S[i], L[i] + S[j]);
		}
		maxS = std::max(maxS, S[i]);
	}
	printf("%d", maxS);
}
