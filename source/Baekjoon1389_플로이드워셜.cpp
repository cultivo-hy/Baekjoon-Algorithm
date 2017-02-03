/*
http://beautyrain.tistory.com/7
for (int i = 0; i < cnt; i++)	memset(list[i], 0, sizeof(int)*cnt);  memset은 0 아니고 1 넣으면 4byte 가 다 1111 1111 1111 1111 되어 이상한 값으로 모두 초기화 됨.
*/
#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
int list[100][101];
int cnt, M;
typedef pair<int, int>ii;
bool comp(ii a, ii b){
	return a.second < b.second ? true : false;
}
int main(){
	cin >> cnt >> M;
	int x, y;
	for (int i = 0; i < M; i++){
		scanf("%d%d", &x, &y);
		list[x - 1][y - 1] = 1;
		list[y - 1][x - 1] = 1;
	}
	for (int i = 0; i < cnt; i++){
		for (int j = 0; j < cnt; j++)
			if (list[i][j] != 1 && i != j)	list[i][j] = 10000;
	}
	//http://koosaga.myungwoo.kr/2
	for (int i = 0; i < cnt; i++){
		for (int j = 0; j < cnt; j++){
			for (int k = 0; k < cnt; k++){
				if (list[j][k] > list[j][i] + list[i][k])
					list[j][k] = list[j][i] + list[i][k];
			}
		}
	}
	vector<ii> result;
	ii tmp;
	int sum = 0;
	for (int i = 0; i < cnt; i++){
		sum = 0;
		for (int j = 0; j < cnt; j++)			sum += list[i][j];
		tmp = make_pair(i, sum);
		result.push_back(tmp);
	}
	sort(result.begin(), result.end(), comp);
	
	cout << result.at(0).first + 1;
}
