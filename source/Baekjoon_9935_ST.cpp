#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
char aList[1000001];
string exploit;
int main(){
	scanf("%s", aList);
	cin >> exploit;
	vector<char> tmp;
	int i = 0;
	int size = exploit.size();
	while (aList[i] != 0){
		tmp.push_back(aList[i]);
		int st = tmp.size();
		if (tmp.back() == exploit.back() && st >=size ){
			int t = 0;
			bool flag = true;
			for (int j = st - size ; j < st; j++){
				if (tmp[j] == exploit[t]) 		t++;
				else{	flag = false;		break; 	}
			}
			if (flag == true){
				for (int i = 0; i < t; i++)	tmp.pop_back();
			}
		}
		i++;
	}
	if (tmp.empty()){
		cout << "FRULA";
	}
	else{
		int st = tmp.size();
		for (int i = 0; i < st; i++)
			cout << tmp[i];
	}
}
