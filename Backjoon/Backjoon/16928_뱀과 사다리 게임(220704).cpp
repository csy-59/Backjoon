#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int n, m;
vector<int> map[101];
int times[101] = { 0 };
int result = -1;

void BFS()
{
	deque<int> q;
	q.push_back(1);
	
	while (q.empty() == false)
	{
		int spot = q.front();
		q.pop_front();

		if (spot == 100)
		{
			result = times[spot];
			break;
		}

		if (map[spot].empty() == false)
		{
			if (times[map[spot][0]] == 0)
			{
				q.push_back(map[spot][0]);
				times[map[spot][0]] = times[spot];
			}
			else if (times[map[spot][0]] > times[spot])
			{
				times[map[spot][0]] = times[spot];
			}

			continue;
		}

		for (int i = 1; i <= 6; ++i)
		{
			if (spot + i > 100)
			{
				break;
			}

			if (times[spot + i] == 0)
			{
				q.push_back(spot + i);
				times[spot + i] = times[spot] + 1;
			}
			else
			{
				if (times[spot + i] > times[spot] + 1)
				{
					times[spot + i] = times[spot] + 1;
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	int s, e;
	for (int i = 0; i < n; ++i)
	{
		cin >> s >> e;
		map[s].push_back(e);
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> s >> e;
		map[s].push_back(e);
	}
	
	BFS();

	cout << result;

	return 0;
}