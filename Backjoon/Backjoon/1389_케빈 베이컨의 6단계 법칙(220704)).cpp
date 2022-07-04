#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> friends[101];
int result[100] = { 0 };
int n, m;

void BFS(int start)
{
	bool isVisited[101] = { false };
	deque<int> q;
	q.clear();
	q.push_back(start);
	isVisited[start] = true;

	int depth = 0;
	while (q.empty() == false)
	{
		const int size = q.size();
		result[start - 1] += depth * q.size();
		++depth;
		for (int count = 0; count < size; ++count)
		{
			int person = q.front();
			q.pop_front();

			for (int i = 0; i < friends[person].size(); ++i)
			{
				if (isVisited[friends[person][i]] == false)
				{
					q.push_back(friends[person][i]);
					isVisited[friends[person][i]] = true;
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

	int start, end;
	for (int i = 0; i < m; ++i)
	{
		cin >> start >> end;
		friends[start].push_back(end);
		friends[end].push_back(start);
	}

	
	int min = 987654321;
	int num = 0;
	for (int i = 1; i <= n; ++i)
	{
		BFS(i);
		if (result[i - 1] < min)
		{
			min = result[i - 1];
			num = i;
		}
	}

	cout << num;

	return 0;
}