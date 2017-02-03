#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int number, condition, compareNum, returnValue, check, result;
int cardList[500001] = { 0 };

int main(){
	scanf("%d", &number);
	for (int i = 0; i < number; i++){
		scanf("%d", &cardList[i]);
	}
	sort(cardList, cardList + number);				// NlogN
	scanf("%d", &condition);
	for (int i = 0; i < condition; i++){				// MlongN
		scanf("%d", &compareNum);
		returnValue = 0;
		int start = 0, end = number - 1;
		result = -1;
		while (start <= end){
			int index = (start + end) / 2;
			if (cardList[index] == compareNum){
				int tmp = index;
				while (tmp >= start){						// 숫자 작은것과 큰것 제외시키면  시간 줄일 수 있음. 0번 부터 N-1 번까지 >> N번 :  n^2 줄일수 있음
					if (cardList[tmp--] < compareNum) break;
					returnValue++;
				}
				tmp = index;
				while (tmp <= end){
					if (cardList[tmp++] > compareNum) break;
					returnValue++;
				}
				returnValue--;
				check = compareNum;
				result = returnValue;
				break;
			}
			else if (cardList[index] > compareNum)		end = index - 1;
			else                                        start = index + 1;
		}
		if (result == -1) {
			result = 0;
			check = 10000001;
		}
		printf("%d ", result);
	}
}
// 3480 KB 384 MS 


/*   79088 KB 312 MS 

#include <cstdio>

#define MAX 10000000
int haveN[2*MAX+1] = { 0 };

int main() {
	int N, M;

	scanf("%d", &N);
	int value = 0;
	for (int i = 0; i < N; ++i) {

	scanf("%d", &value);
	if (value < 0) {
		value = -1 * value + 10000000;
	}
		//printf("%d", value);
		haveN[value]++;
	}

	scanf("%d", &M);

	for (int j = 0; j < M; ++j) {
		int value_m = 0;
		scanf("%d", &value_m);
		if (value_m < 0) {
		value_m = -1 * value_m + 10000000;
		}
		printf("%d ", haveN[value_m]);
	}
}

*/


/*			2916 KB 316 MS 					왼쪽 시작부터 오른쪽 끝까지 찾는 방식
#include<stdio.h>
#include<algorithm>
using namespace std;
int arr[500000];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);
	int m, x;
	//for (int i = 0; i < n; i++)
	//	printf("%d ", arr[i]);
	//printf("\n");
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &x);
		int l1, r1, l2, r2;
		l1 = 0; r1 = n - 1; // 왼쪽을 찾는과정
		while (l1 < r1)
		{
			int mid1 = (l1 + r1) / 2;
			if (arr[mid1] >= x)
				r1 = mid1;
			else
				l1 = mid1 + 1;
		}
		//printf("l1 : %d , r1 : %d\n", l1, r1);
		l2 = 0; r2 = n - 1; // 오른쪽을 찾는 과정
		while (l2 < r2)
		{
			int mid2 = (l2 + r2+1) / 2;
			if (arr[mid2] <= x)
				l2 = mid2;
			else
				r2 = mid2 - 1;
			//printf("l2 : %d , r2 : %d\n", l2, r2);
		}
		if (arr[l2] == x)
			printf("%d ", l2 - l1 + 1);
		else
			printf("0 ");
	}
	printf("\n");
	return 0;
}

*/