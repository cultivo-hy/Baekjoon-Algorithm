/*  Backjoon 9935 랑 똑같은 내용 !_!_!_! 

#include<cstdio>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>
#include<iostream>

using namespace std;

char str1[1000001], str2[101];
int pi[101];
stack<pair<int,int>> s; // str_idx, pi_idx

int main()
{
	scanf("%s %s", str1, str2);

	int j = 0, size2;
	for(int i = 1; str2[i]; i++)
	{
		while(j > 0 && str2[i] != str2[j])
			j = pi[j-1];
		if(str2[i] == str2[j])
			pi[i] = ++j;
		size2 = i;
	}
	size2++;

	j = 0;
	for(int i = 0; str1[i]; i++)
	{
		while(j > 0 && str1[i] != str2[j])
			j = pi[j-1];
		if(str1[i] == str2[j])
		{
			if(j == size2-1)
			{
				while(j--)
					s.pop();
				if(s.empty())
					j = 0;
				else
					j = s.top().second+1;
			}
			else
			{
				s.push(make_pair(i, j));
				j++;
			}
		}
		else
		{
			s.push(make_pair(i, -1));
			j = 0;
		}
	}
	string result;
	while(!s.empty())
	{
		result += str1[s.top().first];
		s.pop();
	}
	reverse(result.begin(), result.end());
	cout << result;
}
*/
#pragma warning(disable:4996)
#include <iostream>
#include <stack>
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
		if (tmp.back() == exploit.back() && st >= size){
			int t = 0;
			bool flag = true;
			for (int j = st - size; j < st; j++){
				if (tmp[j] == exploit[t]) 		t++;
				else{ flag = false;		break; }
			}
			if (flag == true){
				for (int i = 0; i < t; i++)	tmp.pop_back();
			}
		}
		i++;
	}
	int st = tmp.size();
	for (int i = 0; i < st; i++)
		cout << tmp[i];
}