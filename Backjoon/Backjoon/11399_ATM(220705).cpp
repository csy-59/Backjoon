#include <iostream>
#include <algorithm>
using namespace std;

int t;
int atm[1000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	int temp;
	for (int i = 0; i < t; ++i)
	{
		cin >> temp;
		atm[i] = temp;
	}

	sort(atm, atm + t);

	int sum = 0;
	int result = 0;
	for (int i = 0; i < t; ++i)
	{
		sum += atm[i];
		result += sum;
	}

	cout << result;

	return 0;
}