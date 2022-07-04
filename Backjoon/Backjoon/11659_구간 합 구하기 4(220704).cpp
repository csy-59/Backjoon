#include <iostream>
using namespace std;

int nums[100001] = { 0 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	int sum = 0, temp;
	for (int i = 1; i <= n; ++i)
	{
		cin >> temp;
		sum += temp;
		nums[i] = sum;
	}

	int s, e;
	for (int i = 0; i < m; ++i)
	{
		cin >> s >> e;
		cout << nums[e] - nums[s - 1] << "\n";
	}

	return 0;
}