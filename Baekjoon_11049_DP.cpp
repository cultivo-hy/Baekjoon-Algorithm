#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int>ii;
int d[501][501],a,b,dEnd;
int main(){
	int n;
	scanf("%d", &n);
	vector<ii> v(1 + n);
	for (int i = 1; i <= n; i++){
		scanf("%d%d", &a, &b);
		v[i].first = a;
		v[i].second = b;
	}
	for (int l = 1; l<n; l++){
		for (int i = 1; i + l <= n; i++){
			dEnd = i + l;
			d[i][dEnd] = 987654321;
			for (int j = i; j<dEnd; j++)		d[i][dEnd] = min(d[i][j] + d[j + 1][dEnd] + v[i].first* v[j].second*v[dEnd].second, d[i][dEnd]);
		}
	}
	printf("%d", d[1][n]);
	return 0;
}
