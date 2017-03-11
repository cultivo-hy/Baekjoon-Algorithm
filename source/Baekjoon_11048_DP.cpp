#include <cstdio>
#include <queue>
using namespace std;
int S[1001][1001], X, Y;
int main(){
	scanf("%d%d", &X, &Y);
	for (int i = 1; i <= X; i++){
		for (int j = 1; j <= Y; j++){
			scanf("%d", &S[i][j]);
		}
	}
	for (int i = 1; i <= X; i++){
		for (int j = 1; j <= Y; j++){
			S[i][j] = max(S[i - 1][j], S[i][j - 1]) + S[i][j];
		}
	}
	printf("%d", S[X][Y]);
}
