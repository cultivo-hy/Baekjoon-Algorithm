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
