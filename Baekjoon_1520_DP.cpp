#include <cstdio>
#include <cstring>
int S[502][502];
int dp[502][502];
const int left[] = { -1, 1, 0, 0 };
const int right[] = { 0, 0, -1, 1 };
int R, C;
int check(int x, int y){
	if (x == 1 && y == 1) return 1 ;
	int value = dp[x][y];
	if (value != 0) return dp[x][y];
	for (int i = 0; i < 4; i++){
		int nx = x + left[i];
		int ny = y + right[i];
		if (S[x][y] < S[nx][ny] && nx > 0 && nx <= R && ny > 0 && ny <= C){
			value += check(nx, ny);
		}
	}
	dp[x][y] = value;
	return value;
}
int main(){
	memset(S, 1, sizeof(S));
	scanf("%d%d", &R, &C);
	for (int i = 1; i <= R; i++){
		for (int j = 1; j <= C; j++){
			scanf("%d", &S[i][j]);
		}
	}
	printf("%d", check(R, C));
}
