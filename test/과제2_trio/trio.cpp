#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
#define MAX 20

struct set{
	long int i, p, q;
	set(){}
	set(int si, int sp, int sq){
		i = si;
		p = sp;
		q = sq;
	}
}typedef Nset;

bool comp(Nset s1, Nset s2){
	return (s1.p* s2.q) < (s2.p * s1.q);
}
int gcd(int a, int b){
	if (b == 0)
		return a;
	return gcd(b, a%b);
}
using namespace std;

Nset setList[100000];
int intSet[100000];
char list[20];

int main(){
	FILE *inFile = NULL, *outFile = NULL;
	inFile = fopen("trio.inp", "r");
	outFile = fopen("trio.out", "w+");
	int N = 0, pi = 0, qi = 0, great = 0, count = 0, t = 0,inde=0;
	bool flag = true;
	fgets(list, MAX, inFile);
	sscanf(list, "%d\n", &N);
	char c;
	do {
	    c = getc(inFile);
		list[count] = c;
		if ( c >= 48 && c <= 57) 			count++;
		else{
			int ind = count;
			for (int k = 0; k<ind; k++){
				t += (list[k] - '0')*pow(10, count - 1);
				count--;
			}
			if (flag){
				pi = t;
				flag = false;
			}
			else {
				qi = t;
				great = gcd(pi, qi);
				Nset tmp(inde+1, pi / great, qi / great);
				setList[inde++] = tmp;
				flag = true;
			}
			t = 0;
		}
	} while (c != EOF);
	int start = 0, end = 0;
	Nset result(N + 1, 0, 0);
	sort(setList, setList + N, comp);
	for (int j = 0; j < N; j++)		intSet[setList[j].i-1] = j;
	long int value = 0;
	for (int i = 0; i < N - 2; i++){
		if (result.q != 0) 			break;
		int index = intSet[i];
		start = index + 1;
		end = index + 2;
		Nset t1 = setList[index];
		Nset t2 = setList[start];
		Nset t3 = setList[end];
		while (end < N){
			t2 = setList[start];
			t3 = setList[end];
		    value = ((t3.q * t1.p * t2.q) + (t3.q * t1.q * t2.p)) - ((t1.q * t2.q * t3.p));
			if (value == 0){
				if (t1.i < result.i || (t1.i == result.i && t2.i < result.p) || (t1.i == result.i && t2.i == result.p && t3.i < result.q)){
					result.i = t1.i;
					result.p = t2.i;
					result.q = t3.i;
				}
				end++;
			}
			else if (value > 0)	end++;
			else{
				start++;
				if (start == end) end++;
			}
		}
	}
	if (result.q != 0)		fprintf(outFile, "%d %d %d", result.i, result.p, result.q);
	else  		            fprintf(outFile, "%d %d %d",0,0,0);
	fclose(inFile);
	fclose(outFile);
	return 0;
}

