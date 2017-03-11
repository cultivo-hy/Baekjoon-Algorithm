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
