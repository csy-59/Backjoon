#include <iostream>
using namespace std;

int main()
{
	int n, k;
	
	cin >> n >> k;

	int coins[10] = { 1, 0 };
	for (int i = n -1; i >= 0; --i)
	{
		cin >> coins[i];
	}

	int result = 0;
	int i = 0;
	while (k > 0)
	{
		result += k / coins[i];
		k %= coins[i];
		++i;
	}

	cout << result;

	return 0;
}