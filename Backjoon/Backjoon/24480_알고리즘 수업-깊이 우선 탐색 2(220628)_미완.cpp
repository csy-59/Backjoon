#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>

std::vector<int> grid[100001];
int result[100001] = { 0 };
bool isVisited[100001] = { false };
int time = 1;

void dfs(int start)
{
	isVisited[start] = true;
	result[start] = time;
	++time;

	for (int i = grid[start].size() - 1; i >= 0; --i)
	{
		if (isVisited[grid[start][i]] == false)
		{
			dfs(grid[start][i]);
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

	for (int i = 1; i <= m; ++i)
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