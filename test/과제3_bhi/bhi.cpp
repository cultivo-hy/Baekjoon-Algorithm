/*https://www.acmicpc.net/blog/view/25 참고자료
비슷한 문제가 외국에 나온 적 있는것 같아 비슷한 답안의 유형이 나올수도..
*/
#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <algorithm>
#define MAX 20

using namespace std;
typedef pair <int, int> pi;
typedef set <pi >::iterator setIter;

int t, n, res,line;
pi A[10005];
set <pi> S;
char list[MAX];

int dist(int a, int b) {
	return sqrt(pow((A[a].first - A[b].first), 2) + pow((A[a].second - A[b].second), 2));
}

int main()
{
	FILE *inFile = NULL, *outFile = NULL;
	inFile = fopen("bhi.inp", "r");
	outFile = fopen("bhi.out", "w+");
	fgets(list, MAX, inFile);
	sscanf(list, "%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		fgets(list, MAX, inFile);
		sscanf(list, "%d %d", &A[i].first, &A[i].second);
	}
	sort(A, A + n);
	S.clear();		// initialize
	res = 100000;
	for (int i = 0; i < n; i++) {
		while (line < i && A[i].first - A[line].first >= res) {
			S.erase(pi(A[line].second, line++)); 
		}
		setIter leftBound = S.lower_bound(pi(A[i].second - res, 0)), rightBound = S.upper_bound(pi(A[i].second + res, n));
		for (setIter it1 = leftBound; it1 != rightBound; it1++) {
			for (setIter it2 = it1; it2 != rightBound; it2++){
				if (it2 == it1)continue;
				res = min(res, max(dist(i, it1->second), max(dist(i, it2->second), dist(it1->second, it2->second))));
			}
		}
		S.insert(pi(A[i].second, i));
	}
	fprintf(outFile, "%d", res);
	fclose(inFile);
	fclose(outFile);
	return 0;
}
