/*#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;


int x, Min = 0x7fffffff;

void f(int k, int cnt)
{
	if (k<1) return;
	if (k == 1){
		Min = min(Min, cnt);
		return;
	}
	if (k % 3 == 0)f(k / 3, cnt + 1);				// 6의 배수는 3을 그냥 해도 똑같다는 걸 어떻게 알았을까 음 ㅇ.ㅇ
	else{
		if (k % 2 == 0)f(k / 2, cnt + 1);
		f(k - 1, cnt + 1);
	}
}

int main()
{
	scanf("%d", &x);
	f(x, 0);
	printf("%d", Min);
	return 0;
}

*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int list[1000001];

int res=100000;
int g(int N,int count){
	if (list[N] == 0){
		if (N % 3 == 0)  g(N / 3,count+1);
		if (N % 2 == 0)  g(N / 2,count+1);
		if (N > 1)	 g(N - 1,count+1);
	}
	else{
		return res = min(res,list[N] + count);
	}
}
int main(){
	int N;
	cin >> N;
	list[1] = 0;
	list[2] = 1;
	list[3] = 1;
	for (int i = 4; i <= N; i++){
		list[i] = g(i,0); 
		res = 100000;
	}
	cout << list[N];
}
