#include <iostream>

using namespace std;
long long binom[31][31] = { 0 };

/*

int main() {
	int tc;
	cin>>tc;
	while(tc--) {
		int n,m;
		cin>>n>>m;
		unsigned long long int res=1;
		for(int i=0;i<n;i++){
			res*=m-i;			   분자
			res/=i+1;            분모
		}
		cout<<res<<endl;
	}
}

*/
void cacBino()
{
	for (int i = 0; i <= 30; i++) {
		binom[i][0] = binom[i][i] = 1;
		for (int j = 1; j < i; j++)
			binom[i][j] = binom[i - 1][j - 1] + binom[i - 1][j];
	}
}
int main()
{
	int dataCase;
	cin >> dataCase;
	cacBino();
	for (int i = 0; i < dataCase; i++)
	{
		long long leftSite, rightSite;
		cin >> leftSite >> rightSite;
		cout << binom[rightSite][leftSite]<<endl;
	}
}