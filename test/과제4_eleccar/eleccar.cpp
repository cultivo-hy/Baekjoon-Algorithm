#pragma warning(disable:4996)

#include <cstdio>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
using namespace std;

int N, maxV,x,y;
int list[51][51];
int check[51][51];
stack<int> path;
int cnt;

int main(){
	ifstream inStream("eleccar.inp");
	ofstream outStream("eleccar.out");
	inStream >> N;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			inStream >> list[i][j];
			if (list[i][j] != 0 && list[i][j] != 99999)
				check[i][j] = i;
		}
	}
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			for (int k = 0; k < N; k++){
				if (list[k][j] > list[k][i] + list[i][j]){
					list[k][j] = list[k][i] + list[i][j];
					check[k][j] = check[i][j];
				}
			}
		}
	}
	bool flag = false;
	for (int i = 0; i < N; i++){
		if (flag) break;
		for (int j = i; j < N; j++){
			if (j == i && list[i][j] < 0){
				outStream << "nega-cycle";
				flag = true;
				break;
			}
			if (maxV <  list[i][j]){
				maxV = list[i][j];
				x = i;
				y = j;
			}
			if (maxV == 99999){
				outStream << "99999";
				flag = true;
				break;
			}
		}
	}
	if (!flag){
		outStream << maxV << endl;
		int pre = y;
		path.push(y + 1);
		while (x != check[x][pre]){
			pre = check[x][pre];
			path.push(pre + 1);
		}
		outStream << x + 1 << " ";
		while (!path.empty()){
			outStream << path.top() << " ";
			path.pop();
		}
	}
}