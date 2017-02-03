#pragma warning(disable:4996)
#include <cstdio>
typedef long long ll;
int main(){
	int cnt, N;
	scanf("%d", &cnt);
	for (int i = 0; i < cnt; i++){
		scanf("%d", &N);
		ll a = 1, b = 0, c = 1;
		for (int j = 2; j <= N; j++){
			ll temp = 0;
			temp = c;
			c = a + b;
			a = b;
			b = temp;
		}
		printf("%lld\n", c);
	}
}