#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int totalCountNumber;
	int exceptionNumber;
	cin >> totalCountNumber >> exceptionNumber;
	float* scoreList = new float[totalCountNumber];
	float* resultList = new float[2];
	for (int i = 0; i < totalCountNumber; i++)
	{
		float data;
		cin >> data;
		scoreList[i] = data * 10;
	}
	sort(scoreList, scoreList + totalCountNumber);
	float scoreSum = 0;
	for (int i = exceptionNumber; i < totalCountNumber - exceptionNumber; i++)
	{
		scoreSum += scoreList[i];
	}
	float scoreAverage = (scoreSum) / (( totalCountNumber - 2 * exceptionNumber ) * 10);
	cout << fixed;
	cout.precision(2);	
	resultList[0]= scoreAverage;
	for (int i = 0; i < exceptionNumber; i++)
	{
		scoreList[i] = scoreList[exceptionNumber];
	}
	for (int i = exceptionNumber; i >= 0; i--)
	{
		scoreList[totalCountNumber - 1 - i] = scoreList[totalCountNumber - exceptionNumber - 1];
	}
	scoreSum = 0;
	for (int i = 0; i < totalCountNumber; i++)
	{
		scoreSum += scoreList[i];
	}
	scoreAverage = (scoreSum) / (totalCountNumber*10);
	resultList[1] = scoreAverage;
	cout << resultList[0] + 1e-6 << endl;  //1e-6이 필요한 이유!!
	cout << resultList[1] + 1e-6 << endl;
  }