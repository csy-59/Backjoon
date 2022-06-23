#include <stdio.h>
#include <string>
#include <vector>
#include <utility>
using namespace std;

int binomial[31][31];
int binomialNumbers(int n, int k)
{
	if (k <= 0 || k >= n)
	{
		return 1;
	}

	if (binomial[n][k] != 0)
	{
		return binomial[n][k];
	}

	int result = binomialNumbers(n - 1, k - 1) + binomialNumbers(n - 1, k);
	binomial[n][k] = result;
	return result;
}

int main()
{
	int t;
	scanf_s("%d", &t);

	int n;
	string name;
	string type;
	vector<pair<string, int>> items;
	for(int i = 0; i<t;++i)
	{
		scanf_s("%d", &n);
		for (int j = 0; j < n; ++j)
		{
			scanf_s("%s %s", name, type);

		}
	}

	return 0;
}