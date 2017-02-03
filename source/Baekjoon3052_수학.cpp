#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	bool tag[42] = { false, };
	int a = 10,b,count=0;
	while (a--){
		scanf("%d", &b);
		b = b % 42;
		if (tag[b] == false){
			count++;
			tag[b] = true;
		}
	}
	printf("%d", count);
}