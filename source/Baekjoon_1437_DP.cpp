#include <iostream>
#include <queue>
using namespace std;
int dp[1000010];

int main(){
	long long cnt;
	cin >> cnt;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	dp[4] = 4;
	for (int i = 5; i <= cnt; i++){
		dp[i] = (dp[i - 3] * dp[3]) % 10007;
	}
	cout << dp[cnt] % 10007;
}
