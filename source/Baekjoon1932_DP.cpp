#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int list[501] = { 0 };
int num[501][501] = { 0 }; 

int main(){
	int cnt;
	scanf("%d", &cnt);
	for (int i = 0; i<cnt; i++){
		int tmp = 0;
		for (int j = 0; j <= i; j++){
			scanf("%d", &list[j]);
			if (num[i + 1][j] != 0){
				num[i][j] += list[j];
				if (num[i][j] > num[i+1][j]){
					num[i + 1][j] = num[i][j];
					num[i + 1][j + 1] += num[i][j];
				} 
				else{
					num[i + 1][j + 1] += num[i][j];
				}
			}
			else{
				num[i][j] += list[j];
				num[i + 1][j] += num[i][j];
				num[i + 1][j + 1] += num[i][j];
				tmp = list[j];
			}
		}
	}
	sort(num[cnt - 1], num[cnt - 1] + cnt);
	printf("%d", num[cnt - 1][cnt - 1]);
}