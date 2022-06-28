#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>

std::vector<int> grid[100001];
int result[100001] = { 0 };

void dfs(int start)
{
	bool isVisited[100001] = { false };

	std::stack<int> dfs;
	dfs.push(start);

	int round = 1;
	while (dfs.empty() == false)
	{
		int node = dfs.top();
		dfs.pop();
		if (isVisited[node] == false)
		{
			result[node] = round;
			++round;
			isVisited[node] = true;
		}

		for (int i = grid[node].size() - 1; i >= 0; --i)
		{
			int next = grid[node][i];
			if (isVisited[next] == false)
			{
				dfs.push(next);
			}
		}
	}
}

int main()
{
	int n, m, r;
	scanf("%d %d %d", &n, &m, &r);

	int s, e;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d", &s, &e);

		grid[s].push_back(e);
		grid[e].push_back(s);
	}

	for (int i = 1; i <= n; ++i)
	{
		std::sort(grid[i].begin(), grid[i].end());
	}

	dfs(r);

	for (int i = 1; i <= n; ++i)
	{
		printf("%d\n", result[i]);
	}

	return 0;
}