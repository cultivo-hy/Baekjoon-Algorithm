#include <cstdio>
#include <queue>
#include <cmath>
struct list{
	int left, right;
	list(){}
	list(int l,int r){
		left = l;
		right = r;
	}
};
using namespace std;
list S[2][3];
int N, v1;
int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < 3; j++){
			scanf("%d", &v1);
			S[i%2][j] = list(v1, v1);
			if (i == 0) continue;
			if (j == 0){
				S[i % 2][j].left += max(S[(i - 1) % 2][j + 1].left, S[(i - 1) % 2][j].left);
				S[i % 2][j].right += min(S[(i - 1) % 2][j + 1].right, S[(i - 1) % 2][j].right);
			}
			else if (j == 2){
				S[i % 2][j].left += max(S[(i - 1) % 2][j - 1].left, S[(i - 1) % 2][j].left);
				S[i % 2][j].right += min(S[(i - 1) % 2][j - 1].right, S[(i - 1) % 2][j].right);
			}
			else{
				S[i%2][j].left += max(S[(i - 1) % 2][j - 1].left, max(S[(i - 1) % 2][j + 1].left, S[(i - 1) % 2][j].left));
				S[i%2][j].right += min(S[(i - 1) % 2][j - 1].right, min(S[(i - 1) % 2][j + 1].right, S[(i - 1) % 2][j].right));
			}
		}
	}
	printf("%d ", max(S[(N - 1) % 2][0].left, max(S[(N - 1) % 2][1].left, S[(N - 1) % 2][2].left)));
	printf("%d", min(S[(N - 1) % 2][0].right, min(S[(N - 1) % 2][1].right, S[(N - 1) % 2][2].right)));
}
