#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

std::vector<int> grid[100001];
bool isVisited[100001] = { false };
int n, m, r;
int times = 0;
int results[100001] = { 0 };

void bfs(int start)
{
	std::queue<int> bfs;
	isVisited[start] = true;
	results[start] = ++times;
	bfs.push(start);

	while (bfs.empty() == false)
	{
		int node = bfs.front();
		bfs.pop();
		for (int i = 0; i < grid[node].size(); ++i)
		{
			int next = grid[node][i];
			if (isVisited[next] == false)
			{
				isVisited[next] = true;
				results[next] = ++times;
				bfs.push(next);
			}
		}
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &r);
	
	int s, e;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d", &s, &e);

		grid[s].push_back(e);
		grid[e].push_back(s);
	}

	for (int i = 1; i <= n; ++i)
	{
		std::sort(grid[i].begin(), grid[i].end());
	}

	bfs(r);

	for (int i = 1; i <= n; ++i)
	{
		printf("%d\n", results[i]);
	}

	return 0;
}