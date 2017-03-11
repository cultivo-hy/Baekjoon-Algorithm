#include <cstdio>
#include <queue>
int N, list[1001];
int DP[1001];
int maxV;
int main(){
	scanf("%d", &N);
	for (int i = 1; i <= N; i++){
		scanf("%d", &list[i]);
		DP[i] = 1;
	}
	for (int i = 1; i <= N; i++){
		for (int j = 1; j < i; j++){
			if (list[i] > list[j] && DP[i] < DP[j] + 1)
				DP[i] = DP[j] + 1;
		}
	}
	for (int i = 1; i <= N; i++){
		maxV = std::max(maxV, DP[i]);
	}
	printf("%d", maxV);
}
