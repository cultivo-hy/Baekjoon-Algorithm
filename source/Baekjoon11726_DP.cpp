#pragma warning(disable:4996)
#include <cstdio>
int main(){
	int cnt;
	scanf("%d", &cnt);
	int a = 0, b=1, c=0;
	for (int i = 1; i <= cnt; i++){
		c = ( ( b % 10007 ) + ( a % 10007 ) ) % 10007;
		a = b;
		b = c;
	}
	printf("%d", c);
	return 0;
}	
/*
int N[1010];
int main(){
	int cnt;
	scanf("%d", &cnt);
	N[0] = 0;
	N[1] = 1;
	N[2] = 2;
	for (int i = 3; i <= cnt; i++){
		N[i] = ((N[i - 1] % 10007) + (N[i - 2] % 10007)) % 10007;
	}
	printf("%d", N[cnt]);
}
*/