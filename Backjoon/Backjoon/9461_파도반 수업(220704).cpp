#include <iostream>
using namespace std;

long long P[101] = { 0, 1, 1, 1, 2, 2, 3, 4, 5, 7 ,9 };
int t, n;

long long findP(int num)
{
	if (num >= 1 && num <= 3)
		return 1;

	if (P[num] != 0)
		return P[num];

	P[num] = findP(num - 2) + findP(num - 3);
	return P[num];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		cin >> n;
		cout << findP(n) << "\n";
	}

	return 0;
}