// 완전 순열 !_!_!
#include <cstdio>
typedef long long ll;
ll S[1000001];

int main(){
	int N;
	scanf("%d", &N);
	S[1] = 0;
	S[2] = 1;
	S[3] = 2;
	for (int i = 4; i <= N; i++){
		S[i] = (i - 1) * (S[i - 1] + S[i - 2]) % 1000000000;
	}
	printf("%lld", S[N] % 1000000000);
}