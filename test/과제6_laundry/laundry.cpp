#include <cstdio>
#include <cmath>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;
int N, T, C, M, S[16][2], L[16][16];
vector<int> list, result;
bool check[16], endFlag;

int dist(int x1, int y1, int x2, int y2){
	return (abs(x1 - x2) + abs(y1 - y2));
}

bool isAllCheck(){
	bool R = true;
	for (int i = 0; i < N; i++){
		R *= check[i];
	}
	return R;
}
void roam(int index){
	list.push_back(index);
	if (C < T){
		for (int i = 1; i < N; i++){
			if (!check[i] && !endFlag){
				C += L[index][i];
				check[i] = true;
				roam(i);
			}
		}
	}
	if (isAllCheck()){
		int value = C + L[index][0];
		if (value <= T){
			if (value > M){
				M = value;
				result.clear();
				for (int i = 0; i < list.size(); i++){
					result.push_back(list[i] + 1);
				}
				if (value == T){
					endFlag = true;
					return;
				}
			}
		}
	}
	check[index] = false;
	list.pop_back();
	if (list.size() != 0)	C -= L[list.back()][index];
}
int main(){
	ifstream inStream("laundry.inp");
	ofstream outStream("laundry.out");
	inStream >> N >> T;
	for (int i = 0; i < N; i++)
		inStream >> S[i][0] >> S[i][1];
	for (int i = 0; i < N; i++){
		for (int j = i + 1; j < N; j++){
			L[i][j] = dist(S[i][0], S[i][1], S[j][0], S[j][1]);
			L[j][i] = L[i][j];
		}
	}
	check[0] = true;
	roam(0);
	if (result.size() != 0){
		for (int i = 0; i < result.size(); i++)
			outStream << result[i] << " ";
	}
	else
		outStream << 0;
}