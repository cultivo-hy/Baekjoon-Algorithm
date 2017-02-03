#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <math.h>
#include <climits>
#include <algorithm>
using namespace std;

int ddp[100001];

int main(){
	int result;
	cin >> result;
	for (int i = 1; i <= result; i++){
		ddp[i] = INT_MAX;
	}
	int cnt = sqrt(result);
	for (int i = 1; i <= cnt; i++){
		for (int j = 1; j <= result; j++){
			if (j - i*i >= 0 && ddp[j - i*i] != INT_MAX){
				ddp[j] = min(ddp[j], ddp[j - i*i]+ 1);
			}
		}
	}
	cout << ddp[result];
}
