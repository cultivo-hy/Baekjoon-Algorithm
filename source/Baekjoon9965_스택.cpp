#pragma warning(disable:4996)
#include <iostream>
#include <stack>
#include <string>
using namespace std;
char aList[1000001];
string exploit;
int main(){
	scanf("%s", aList);
	cin >> exploit;
	stack<char> tmp;
	int i = 0;
	int size = exploit.size();
	while (aList[i] != 0){
		if (aList[i] == exploit.back()){
			int t = 0;
			bool flag = true;
			for (int j = i - size + 1; j <= i; j++){
				if (aList[j] == exploit[t]) 		t++;
				else{
					flag = false;
					break;
				}
			}
			if (flag == true){
				for (int i = 0; i < t - 1; i++){
					tmp.pop();
				}
			}
		}
		else {
			tmp.push(aList[i]);
		}
		i++;
	}
	int s = tmp.size();
	for (int i = s; i >0; i--){
		aList[s - 1] = tmp.top();
		tmp.pop();
	}
	cout << aList;
}