/*

d[n] = 2*n ���� ���� ��� ����� ��

����   d[n-2]  // �Ѵ� ���� ��                   
����   d[n-1]  // �ǵ� ���� �� (n-1 ���� �ְų� ���ų�,)
����   d[n-1]  // �� �ڿ� ���� �� (n-1 ������ �ڵ� ����)           

=>
d[n] = d[n-2]+d[n-1]*2;

Ȥ��
list[0][0] =1  // list[0][1] =1          //list[0][2] =1
���� ���       ���ʿ� �ִ� ���     �����ʿ� �ִ� ���

list[1][0] = list[0][0] + list[0][1] +list[0][2];
list[1][1] = list[0][0] + list[0][2];
list[1][2] = list[0][0] + list[0][1];

list[2][0] = list[1][0] + list[1][1] + list[1][2];
list[2][1] = list[1][0] + list[1][2];
list[2][2] = list[1][0] + list[1][1];
...

result = list[n-1][0] + list[n-1][1] + list[n-1][2];

*/
#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>

using namespace std;
int list[100001] = { 0 };
int main(){
	int num;
	scanf("%d", &num);
	list[0] = 1;
	list[1] = 3;
	for (int i = 2; i <= num; i++){
		list[i] = (list[i - 2] + list[i - 1] * 2)%9901;
	}
	printf("%d", list[num]);
}