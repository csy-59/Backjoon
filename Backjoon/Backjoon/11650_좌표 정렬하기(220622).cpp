#include <stdio.h>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

//cmp 함수 정확히 쓰자....
bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.first < b.first)
	{
		return true;
	}
	else if (a.first > b.first)
	{
		return false;
	}
	else
	{
		return a.second < b.second;
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