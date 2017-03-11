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
			S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + value;
		}
	}
	fscanf(inFile, "%d", &count);
	for (int i = 0; i < count; i++){
		int x1, x2, y1, y2;
		fscanf(inFile, "%d %d %d %d", &y1, &y2, &x1, &x2);
		fprintf(outFile, "%d\n", S[x2][y2] - S[x2][y1 - 1] - S[x1 - 1][y2] + S[x1 - 1][y1 - 1]);
	}
	fclose(inFile);
	fclose(outFile);
	return 0;
}