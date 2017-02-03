/*
#include <cstdio>

char s[1000001], t[44], r[1000001];

int main()
{
	int i, j, n, m = 0;
	scanf("%s%s", s, t);
	for (n = 0; t[n]; n++);
	for (i = 0; s[i]; i++)
	{
		r[m++] = s[i];
		if (m >= n)
		{
			for (j = 0; j < n; j++) if (r[j + m - n] != t[j]) break;
			if (j == n) m -= n;
		}
	}
	r[m] = 0;
	puts(m ? r : "FRULA");
}
*/

#pragma warning(disable:4996)
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <stack>
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