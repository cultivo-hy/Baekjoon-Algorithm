#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int list[101];
int ddp[10010];

int main(){
	int result;
	int cnt;
	cin >> cnt >> result;
	for (int i = 1; i <= cnt; i++){
		scanf("%d", &list[i]);	
	}
	for (int i = 1; i <= result; i++){
		ddp[i] = -1;
	}
	sort(list, list + cnt);
	for (int i = 1; i <= cnt; i++){
		for (int j = 1; j <= result; j++){
			if (j - list[i] >= 0){
				if (ddp[j - list[i]] != -1){
					if (ddp[j] != -1)
						ddp[j] = min(ddp[j], ddp[j - list[i]] + 1);
					else
						ddp[j] = ddp[j - list[i]] + 1;
				}
			}
		}
	}
	cout << ddp[result];
}
