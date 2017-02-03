#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int result[1001][3] = { 0 };
int main(){
	int cnt;
	scanf("%d", &cnt);
	scanf("%d %d %d", &result[0][0], &result[0][1], &result[0][2]);
	for (int i = 1; i < cnt; i++){
			scanf("%d %d %d", &result[i][0], &result[i][1], &result[i][2]);
			result[i][0] += ((result[i - 1][1] > result[i - 1][2]) ? result[i - 1][2] : result[i - 1][1]);
			result[i][1] += ((result[i - 1][0] > result[i - 1][2]) ? result[i - 1][2] : result[i - 1][0]);
			result[i][2] += ((result[i - 1][0] > result[i - 1][1]) ? result[i - 1][1] : result[i - 1][0]);
	}
	sort(result[cnt - 1], result[cnt - 1] +3);
	printf("%d", result[cnt - 1][0]);
}