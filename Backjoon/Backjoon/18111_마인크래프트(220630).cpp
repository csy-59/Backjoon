#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

int n, m, b;
int counts[257] = { 0 };


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m >> b;

	int temp;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> temp;
			++counts[temp];
		}
	}

	int minTime = 99999999;
	int maxHeight = 0;
	for (int i = 0; i <= 256; ++i)
	{
		int currentTime = 0;

		int subblock = 0;
		for (int j = i + 1; j <= 256; ++j)
		{
			subblock += counts[j] * (j - i);
		}

		int addblock = 0;
		for (int j = 0; j < i; ++j)
		{
			addblock += counts[j] * (i - j);
		}

		if (addblock > b + subblock)
			continue;

		currentTime += addblock + subblock * 2;

		if (minTime > currentTime)
		{
			minTime = currentTime;
			maxHeight = i;
		}
		else if (minTime == currentTime && maxHeight < i)
		{
			maxHeight = i;
		}
	}

	cout << minTime << " " << maxHeight << "\n";

	return 0;
}