#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std; 


int cnt;
long long result;
int aList[1000001] = { 0 };
int value;

int binarySearch(int start, int end){
	int mid = (start + end) / 2;
	if (start > end){
		return value;
	}
	long long sum = 0;
	for (int i = 0; i < cnt; i++){
		if (aList[i] - mid > 0)
			sum += (aList[i] - mid);
	}
	if (sum > result){
		value = mid;
		binarySearch(mid + 1, end);
	}
	else if (sum < result)			binarySearch(start,mid-1);
	else{
		return mid;
	}
}
int main(){
	scanf("%d", &cnt);
	scanf("%I64d", &result);
	for (int i = 0; i < cnt; i++)
		scanf("%d", &aList[i]);
	sort(aList, aList + cnt);
	int length = aList[cnt - 1];
	printf("%d",binarySearch(0, length));
}
