#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int n, p1, p2;
vector<int> family[101];
int result = -1;

void BFS()
{
	bool isVisited[101] = { false };
	deque<int> q;
	q.push_back(p1);
	isVisited[p1] = true;

	int current = 0;
	while (q.empty() == false)
	{
		const int size = q.size();

		for (int i = 0; i < size; ++i)
		{
			int person = q.front();
			q.pop_front();

			if (person == p2)
			{
				result = current;
				q.clear();
				break;
			}

			for (int i = 0; i < family[person].size(); ++i)
			{
				if (isVisited[family[person][i]] == false)
				{
					q.push_back(family[person][i]);
					isVisited[family[person][i]] = true;
				}
			}
		}

		++current;
	}

}

int main()
{
	cin >> n >> p1 >> p2;

	int t;
	cin >> t;
	int s, e;
	for (int i = 0; i < t; ++i)
	{
		cin >> s >> e;
		family[s].push_back(e);
		family[e].push_back(s);
	}

	BFS();

	cout << result;

	return 0;
}