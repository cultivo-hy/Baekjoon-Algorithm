#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

int S[1001][1001];
using namespace std;

int main(){
	FILE *inFile = NULL, *outFile = NULL;
	inFile = fopen("login.inp", "r");
	outFile = fopen("login.out", "w+");

	int iL = 0, iR = 0, value = 0, count = 0;
	fscanf(inFile, "%d", &iL);
	fscanf(inFile, "%d", &iR);
	for (int i = 1; i <= iL; i++){
		for (int j = 1; j <= iR; j++){
			fscanf(inFile, "%d", &value);
			S[i][j] = value;
		}
	}
	fscanf(inFile, "%d", &count);
	for (int i = 0; i < count; i++){
		int x1, x2, y1, y2;
		value = 0;
		fscanf(inFile, "%d %d %d %d", &y1, &y2, &x1, &x2);
		for (int j = x1; j <= x2; j++){
			for (int k = y1; k <= y2; k++){
				value += S[j][k];
			}
		}
		fprintf(outFile, "%d\n", value);
	}
	fclose(inFile);
	fclose(outFile);
	return 0;
}