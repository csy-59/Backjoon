/*
* [파티]
* - 모든 노드에서 특정 노드까지 가는 최단 거리를 모두 구해야함
* - 그중 가장 긴 거리를 출력하는 문제
* 
* <내 생각>
* - 다익스트라 알고리즘을 활용한다
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int n, m, x;
int s, e, t;
int i;
int INF = 999999;
vector<pair<int, int>> road[1000];
vector<int> endRoad(1000, INF);

struct cmp
{
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		return a.second > b.second;
	}
};

int Dijstra(int start, int end)
{
	if (start == end)
		return 0;

	vector<int> arr(n, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> open;

	// 초기화
	arr[start] = 0;
	open.push(make_pair(start, 0));

	while (open.empty() == false)
	{
		pair<int, int> cur = open.top();
		open.pop();

		int curNode = cur.first;
		int curDistance = cur.second;

		for (int i = 0; i < road[curNode].size(); ++i)
		{
			// <노드 번호, 가중치>
			pair<int, int> next = road[curNode][i];

			int newDistance = curDistance + next.second;
			if (newDistance < arr[next.first])
			{
				arr[next.first] = newDistance;
				open.push(make_pair(next.first, newDistance));
			}
		}

		bool isOver = true;
	}

	return arr[end];
}

int main()
{
	scanf("%d %d %d", &n, &m, &x);
	--x;

	for (i = 0; i < m; ++i)
	{
		scanf("%d %d %d", &s, &e, &t);
		road[s - 1].push_back(make_pair(e - 1, t));
	}

	int answer = 0;
	for (i = 0; i < n; ++i)
	{
		int temp = Dijstra(i, x) + Dijstra(x, i);
		if (temp > answer) answer = temp;
	}

	printf("%d", answer);

	return 0;
}