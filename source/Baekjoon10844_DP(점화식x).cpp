#pragma warning(disable:4996)
#include <cstdio>
#define MOD 1000000000
typedef long long ll;
ll S[10],T[10];
int main(){
	for (int i = 1; i < 10; i++){
		S[i] = 1;
		T[i] = S[i];
	}
	int cnt;
	scanf("%d", &cnt);
	for (int j = 1; j < cnt; j++){
		for (int i = 0; i < 10; i++){
			if (i == 0) S[0] = T[1] % MOD;
			else if (i == 9) 	S[9] = T[8] % MOD;
			else	S[i] = (T[i - 1] % MOD + T[i + 1] % MOD) % MOD;
		}
		for (int i = 0; i < 10; i++)
			T[i] = S[i];
	}
	ll result = 0;
	for (int j = 0; j < 10; j++){
		result = (result + T[j]) % MOD;
	}
	printf("%lld", result % MOD);
}