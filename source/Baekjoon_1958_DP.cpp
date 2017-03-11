#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;
char t1[101], t2[101], t3[101];
int s1, s2, s3, dp[102][102][102];
int main(){
	gets(t1);
	gets(t2);
	gets(t3);
	s1 = strlen(t1);
	s2 = strlen(t2);
	s3 = strlen(t3);
	for (int i = 1; i <= s1; i++){
		for (int j = 1; j <= s2; j++){
			for (int k = 1; k <= s3; k++){
				if ( t1[i - 1] == t2[j - 1] && t1[i - 1] == t3[k - 1] ){
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				}
				else{
					dp[i][j][k] = max(dp[i - 1][j][k] , max(dp[i][j - 1][k] , dp[i][j][k - 1]));
				}
			}
		}
	}
	printf("%d", dp[s1][s2][s3]);
}
