#include <cstdio>
int N, list[2001],C;
bool dp[2001][2001];

bool check(int start, int end){
	while (start <= end){
		if (list[start] != list[end]) {
			return false;
		}
		start++;
		end--;
	}
	return true;
}
int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &list[i]);
	for (int i = 0; i < N; i++) dp[i][i] = true;

	for (int i = 1; i < N; i++)
		dp[0][i] = check(0, i);
	
	for (int i = 1; i < N; i++){
		for (int j = i + 1; j < N; j++){
			if (dp[i-1][j+1] == 0 || j == N - 1)
				dp[i][j] = check(i, j);
			else dp[i][j] = dp[i - 1][j + 1];
		}
	}
	scanf("%d", &C);
	int a, b = 0;
	for (int i = 0; i < C; i++){
		scanf("%d %d", &a, &b);
		printf("%d\n", dp[a-1][b-1]);
	}
}
