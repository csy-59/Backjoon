#include <iostream>
#include <utility>
using namespace std;

pair<int, int> fibo[41] = {
	{1, 0}, {0, 1}, {1, 1}, {1, 2}
};

pair<int, int> fibonacci(int n)
{
	if (n == 1)
	{
		fibo[n].first = 0;
		fibo[n].second = 1;

		return fibo[n];
	}

	if (n == 0)
	{
		fibo[n].first = 1;
		fibo[n].second = 0;

		return fibo[n];
	}

	if (fibo[n].first != 0 || fibo[n].second != 0)
	{
		return fibo[n];
	}

	pair<int, int> b = fibonacci(n - 1);
	pair<int, int> bb = fibonacci(n - 2);

	fibo[n].first = b.first + bb.first;
	fibo[n].second = b.second + bb.second;

	return fibo[n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;
	
	int temp;
	for (int i = 0; i < t; ++i)
	{
		cin >> temp;
		pair<int, int> result = fibonacci(temp);
		cout << result.first << " " << result.second << "\n";
	}

	return 0;
}