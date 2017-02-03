
/*
#include <iostream>
#include <utility>
#include <limits.h>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>

typedef long long ll;
using namespace std;


int main(){

int n;
stack<double> st;
string data;
vector<double> values(30, 0);
double ans = 0.0;
cin >> n;
cin >> data;
for (int i = 0; i < n; i++)
cin >> values[i];
	for (int i = 0; i < data.size(); i++){
		char cur = data[i];
		if (cur >= 'A' && cur <= 'Z'){
			st.push(values[cur - 'A']);
		}
		else{
		double operand_1 = st.top();
		st.pop();
		double operand_2 = st.top();
		st.pop();
		if (cur == '+')
			st.push(operand_2 + operand_1);
		else if (cur == '-')
			st.push(operand_2 - operand_1);
		else if (cur == '*')
			st.push(operand_2 * operand_1);
		else
			st.push(operand_2 / operand_1);
		}
	}
	printf("%.2lf\n", st.top());
}


*/
#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

string list[60];
string alpa[26] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"  }; 
int main(){					// ASCII 코드 A 는 65  숫자 1은 50
	double cnt,val;
	string tmp;
	cin >> cnt >>  tmp;
	int size = tmp.size();
	for (int j = 0; j < size; j++)		list[j] = tmp[j];
	for (int i = 0; i < cnt; i++){
		cin >> val;
		for (int j = 0; j < size; j++){
			if (list[j].compare(alpa[i])==0)		list[j] = to_string(val);
		}
	}
	vector<double> result;
	for (int i = 0; i < size; i++){
		if (list[i].compare("*") == 0 || list[i].compare("/") == 0 || list[i].compare("+") == 0 || list[i].compare("-") == 0){
			double a = 0, b = 0, c = 0;
			b = result.at(result.size() - 1);
			result.pop_back();
			a = result.at(result.size() - 1);
			result.pop_back();
			if (list[i].compare("*") == 0)					c = a * b;
			else if (list[i].compare("/") == 0)				c = a / b;
			else if (list[i].compare("+") == 0)			c = a + b;
			else		c = a - b;
			result.push_back(c);
		}
		else{
			result.push_back(atoi(list[i].c_str()));
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << result.at(0);
}

