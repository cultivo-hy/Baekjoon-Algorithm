#pragma warning(disable:4996)
#include <cstdio>
#define MOD 10007
int main(){
	int cnt;
	scanf("%d", &cnt);
	int a = 1, b = 1, c = 1;
	for (int i = 1; i < cnt; i++){
		c = ((b % MOD) + (2 * a % MOD)) % MOD;
		a = b;
		b = c;
	}
	printf("%d", c);
}
/*
int N[1010];
	int main(){
	int cnt;
	scanf("%d", &cnt);
	N[0] = 0;
	N[1] = 1;
	N[2] = 3;
	for (int i = 3; i <= cnt; i++){
		N[i] = ((N[i - 1] % 10007) + (2 * N[i - 2] % 10007)) % 10007;
	}
	printf("%d", N[cnt]);
}
*/