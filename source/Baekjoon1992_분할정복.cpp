/*
string tmp;
for (int i = 0; i < num; i++){
cin >> tmp;
memcpy(list[i], tmp.c_str(), strlen(tmp.c_str()) + 1);		//	strcpy(list[i] , tmp.c_str());  memcpy 와 strcpy 의 차이점!!
}
*/

#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <string.h>
#define ZERO 48

using namespace std;
char list[64][65];
bool flag = true;

void compact(int x, int y, int size){
	if (size == 1){	printf("%c", list[x][y]);	return;  	}
	for (int k = 0; k < 2; k++){
		for (int i = x; i < x + size; i++){
			for (int j = y; j < y + size; j++){
				if (list[i][j] == ZERO+k){  flag = false;   break;   }
			}
		}
		if (flag == true) { printf("%c", ZERO + 1 - k); return; }
		flag = true;
	}
	int tmp = (size / 2);
	printf("(");
	compact(x, y, tmp);
	compact(x, y + tmp, tmp);
	compact(x + tmp, y, tmp);
	compact(x + tmp, y + tmp, tmp);
	printf(")");
}
int main(){
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) { cin >> list[i]; }
	compact(0, 0, num);
}

