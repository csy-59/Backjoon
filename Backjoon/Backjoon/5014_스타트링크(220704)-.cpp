#include <iostream>
#include <deque>
using namespace std;

int f, s, g, u, d;
int floors[1000001] = { 0 };
int result = -1;

void BFS()
{
	deque<int> q;
	q.push_back(s);
	floors[s] = 1;

	static const int add[2] = { u, -d };

	while (q.empty() == false)
	{
		int currentFloor = q.front();
		q.pop_front();

		if (currentFloor == g)
		{
			result = floors[currentFloor];
			return;
		}

		for (int i = 0; i < 2; ++i)
		{
			int newFloor = currentFloor + add[i];

			if (newFloor < 1 || newFloor >f)
				continue;

			if (floors[newFloor] != 0)
				continue;

			q.push_back(newFloor);
			floors[newFloor] = floors[currentFloor] + 1;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> f >> s >> g >> u >> d;

	BFS();

	if (result == -1)
	{
		cout << "use the stairs";
	}
	else
	{
		cout << result - 1;
	}

	return 0;
}