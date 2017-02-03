#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
using namespace std;
int N[21];
int S[10010];
int main(){
	int cnt,n,money;
	scanf("%d", &cnt);
	for (int i = 0; i < cnt; i++){
		scanf("%d", &n);
		for (int j = 0; j < n; j++){
			scanf("%d", &N[j]);
		}
		scanf("%d", &money);
		S[0] = 1;
		for (int k = 0; k < n; k++){
			for (int j = 1; j <= money; j++){
				if (j - N[k] >= 0){
					S[j] = S[j] + S[j - N[k]];
				}
			}
		}
		printf("%d\n", S[money]);
		memset(N, 0, sizeof(int) * 21);
		memset(S, 0, sizeof(int) * 10010);
	}
}