#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	string s;
	cin >> s;

	unsigned long long result = 0;
	unsigned long long threeone = 1;
	for (int i = 0; i < n; ++i)
	{
		result += ((s[i] - 'a' + 1) * threeone);
		threeone *= 31;
		threeone %= 1234567891;
	}

	cout << result % 1234567891;

	return 0;
}