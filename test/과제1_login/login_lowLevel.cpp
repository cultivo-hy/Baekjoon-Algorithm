#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cmath>
#define MAX 5000
int S[1001][1001];
using namespace std;
char list[5000];

int main(){
	FILE *inFile = NULL, *outFile = NULL;
	inFile = fopen("login.inp", "r");
	outFile = fopen("login.out", "w+");
	int iL = 0, iR = 0, value = 0, count = 0;
	fgets(list, MAX, inFile);
	sscanf(list, "%d %d", &iL, &iR);
	string tmp = "";
	for (int i = 1; i <= iL; i++){
		fgets(list, MAX, inFile);
		int count = 0, t, jndex = 1, ss = 0;
		for (int j = 0; j < MAX; j++){
			t = 0;
			if (list[j] == 10) {
				ss = j;		break;
			}
			if (list[j] != ' ') count++;
			else{
				for (int k = count; k > 0; k--){
					t += (list[j - count] - '0')*pow(10, count - 1);
					count--;
				}
				S[i][jndex] = S[i - 1][jndex] + S[i][jndex - 1] - S[i - 1][jndex - 1] + t;
				jndex++;
			}
		}
		for (int k = count; k > 0; k--){
			t += (list[ss - count] - '0')*pow(10, count - 1);
			count--;
		}
		S[i][jndex] = S[i - 1][jndex] + S[i][jndex - 1] - S[i - 1][jndex - 1] + t;
	}
	fgets(list, MAX, inFile);
	sscanf(list, "%d", &count);
	for (int i = 0; i < count; i++){
		int x1, x2, y1, y2;
		value = 0;
		fgets(list, MAX, inFile);
		sscanf(list, "%d %d %d %d", &y1, &y2, &x1, &x2);
		fprintf(outFile, "%d\n", S[x2][y2] - S[x2][y1 - 1] - S[x1 - 1][y2] + S[x1 - 1][y1 - 1]);
	}
	fclose(inFile);
	fclose(outFile);
	return 0;
}