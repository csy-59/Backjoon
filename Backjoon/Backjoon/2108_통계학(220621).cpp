#include <algorithm>
#include <stdio.h>
#include <cmath>
using namespace std;

//자료형 범위를 제대로 보자
int main()
{	
	printf("%d", 5/ 2);

	int inputCount;
	scanf_s("%d", &inputCount);

	int numCounts[8001] = { 0 };
	short* list = new short[inputCount];
	int sum = 0;

	for (int i = 0; i < inputCount; ++i)
	{
		int temp;
		scanf_s("%d", &temp);

		int index = temp + 4000;
		++numCounts[index];
		list[i] = temp;
		sum += temp;
	}

	std::sort(list, list + inputCount);

	//산술 평균
	printf("%d\n", (int) round((double) sum / inputCount));
	
	//중앙값
	printf("%d\n", list[inputCount / 2]);
	
	//최빈값
	int maxCount = 0;
	int index = 0;

	for (int i = 0; i < 8001; ++i)
	{
		if (maxCount < numCounts[i])
		{
			maxCount = numCounts[i];
			index = i - 4000;
		}
	}
	for (int i = index + 4001; i < 8001; ++i)
	{
		if (maxCount == numCounts[i])
		{
			index = i - 4000;
			break;
		}
	}

	printf("%d\n", index);

	//범위
	printf("%d\n", abs(list[inputCount-1] - list[0]));

	return 0;
}