#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int number;
int condition;
int compareNum;
int cardList[500001] = { 0 };
int resultArray[500001] = { 0 };

bool binarySearch(int start, int end){
	int index = (start + end) / 2;
	if (start > end)										return false;
	if (cardList[index] == compareNum)			return true;
	else if (cardList[index] > compareNum)		binarySearch(start, index - 1);
	else                                                   binarySearch(index + 1, end);
}

int main(){
	scanf("%d", &number);
	for (int i = 0; i < number; i++){
		scanf("%d", &cardList[i]);
	}
	sort(cardList, cardList + number);
	scanf("%d", &condition);
	for (int i = 0; i < condition; i++){
		scanf("%d", &compareNum);
		bool result = binarySearch(0, number - 1);
		if (result)			resultArray[i] = 1;
	}
	for (int i = 0; i < condition; i++)
		cout << resultArray[i] << " ";
}
//  À§¿¡ ²¨   5432 KB   360 MS
//  ¹Ø¿¡ ²¨   3480 KB   432 MS 
/*

#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int number;
int condition;
int compareNum;
int cardList[500001] = { 0 };

bool binarySearch(int start, int end){
	int index = (start + end) / 2;
	if (start > end)										return false;
	if (cardList[index] == compareNum)			return true;
	else if (cardList[index] > compareNum)		binarySearch(start, index - 1);
	else                                                   binarySearch(index + 1, end);
}

int main(){
	scanf("%d", &number);
	for (int i = 0; i < number; i++){
		scanf("%d", &cardList[i]);
	}
	sort(cardList, cardList + number);
	scanf("%d", &condition);
	for (int i = 0; i < condition; i++){
		scanf("%d", &compareNum);
		bool result = binarySearch(0, number - 1);
		int value = 0;
		if (result)  value = 1;
		printf("%d ",value);
	}
}


*/ 