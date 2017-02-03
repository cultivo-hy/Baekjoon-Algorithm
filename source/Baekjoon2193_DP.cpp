#pragma warning(disable:4996)
#include <cstdio>
typedef long long ll;
int main(){
	int N;
	scanf("%d", &N);
	ll a = 1, b = 0, c = 0;
	for (int i = 0; i < N; i++){
		c = a + b;
		a = b;
		b = c;
	}
	printf("%lld", c);
}