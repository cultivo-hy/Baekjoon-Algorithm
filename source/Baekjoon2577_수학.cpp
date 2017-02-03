#pragma warning(disable:4996);
#include <cstdio>

int list[10] = { 0 };
int main()
{
	int num,multiple=1;
	for (int i = 0; i < 3; i++){
		scanf("%d", &num);
		multiple = multiple * num;
	}
	while (multiple != 0) {
		int count = 0;
		count = multiple % 10;
		list[count]++;
		multiple = multiple / 10;
	}
	for (int i = 0; i < 10; i++) printf("%d\n", list[i]);
}