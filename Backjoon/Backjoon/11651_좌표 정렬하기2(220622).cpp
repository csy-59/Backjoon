#include <stdio.h>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

//cmp 함수 정확히 쓰자....
bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.second < b.second)
	{
		return true;
	}
	else if (a.second > b.second)
	{
		return false;
	}
	else
	{
		return a.first < b.first;
	}
}

int main()
{
	int inputCount;
	scanf_s("%d", &inputCount);

	vector<pair<int, int>> pointArr;
	for (int i = 0; i < inputCount; ++i)
	{
		int first, second;
		scanf_s("%d %d", &first, &second);

		pointArr.push_back({ first, second });
	}

	sort(pointArr.begin(), pointArr.end(), cmp);

	for (int i = 0; i < inputCount; ++i)
	{
		printf("%d %d\n", pointArr[i].first, pointArr[i].second);
	}

	return 0;
}