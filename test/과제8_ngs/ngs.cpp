#pragma warning(disable:4996)
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#define MAX 51
using namespace std;

char list[MAX];
string result[200000];

int main(){
	FILE *inFile = NULL;
	inFile = fopen("ngs.inp", "r");
	ofstream outStream("ngs.out");
	int index = 0;
	while (fscanf(inFile, "%s", list) != EOF) {
		result[index] = list;
		index++;
	}
	sort(result, result + index);
	string tmp = result[0];
	int allCount = 1;
	int tCount = 1;
	int maxV = 0;
	int temp;
	for (int i = 1; i < index; i++){
		temp = 0;
		if (tmp.size() == result[i].size()){
			for (int j = 0; j < tmp.size(); j++){
				if (tmp[j] == result[i][j]) {
					continue;
				}
				temp = 1;
				break;
			}
		}
		else	temp = 1;
		if (temp == 0)		tCount++;
		else{
			if (allCount < tCount){
				allCount = tCount;
				maxV = i - 1;
			}
			tCount = 1;
			tmp = result[i];
		}
	}
	outStream << result[maxV];
}