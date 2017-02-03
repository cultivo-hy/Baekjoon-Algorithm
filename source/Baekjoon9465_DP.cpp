#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int N[3][100002] = { 0, };
int main(){
	int cnt, n;
	scanf("%d", &cnt);
	for (int i = 0; i < cnt; i++){
		scanf("%d",&n);
		for (int j = 0; j < 2; j++){
			for (int k = 0; k < n; k++){
				scanf("%d", &N[j][k] );
			}
		}
		for (int j = 1; j < n; j++){
			N[0][j] = N[0][j] + (( N[1][j - 1] > N[2][j - 1]) ? N[1][j - 1] : N[2][ j - 1 ] );
			N[1][j] = N[1][j] + (( N[0][j - 1] > N[2][j - 1]) ? N[0][j - 1] : N[2][ j - 1 ] );
			N[2][j] = N[2][j] + (( N[0][j - 1] > N[1][j - 1]) ? N[0][j - 1] : N[1][ j - 1 ] );
		}
		int a = N[0][n - 1] > N[1][n - 1] ? N[0][n - 1] : N[1][n - 1];
		printf("%d\n", (a > N[2][n-1] ? a : N[2][n-1] ));
		for (int i = 0; i < 3; i++)
			memset(N[i], 0, sizeof(int)*n);
	}
}