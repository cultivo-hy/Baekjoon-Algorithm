/*

d[n] = 2*n 에서 있을 모든 경우의 수

ㅁㅁ   d[n-2]  // 둘다 없을 때                   
ㅁㅁ   d[n-1]  // 맨뒤 없을 때 (n-1 까진 있거나 없거나,)
ㅁㅁ   d[n-1]  // 맨 뒤에 있을 때 (n-1 떄문에 자동 결정)           

=>
d[n] = d[n-2]+d[n-1]*2;

혹은
list[0][0] =1  // list[0][1] =1          //list[0][2] =1
없는 경우       왼쪽에 있는 경우     오른쪽에 있는 경우

list[1][0] = list[0][0] + list[0][1] +list[0][2];
list[1][1] = list[0][0] + list[0][2];
list[1][2] = list[0][0] + list[0][1];

list[2][0] = list[1][0] + list[1][1] + list[1][2];
list[2][1] = list[1][0] + list[1][2];
list[2][2] = list[1][0] + list[1][1];
...

result = list[n-1][0] + list[n-1][1] + list[n-1][2];

*/
#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>

using namespace std;
int list[100001] = { 0 };
int main(){
	int num;
	scanf("%d", &num);
	list[0] = 1;
	list[1] = 3;
	for (int i = 2; i <= num; i++){
		list[i] = (list[i - 2] + list[i - 1] * 2)%9901;
	}
	printf("%d", list[num]);
}