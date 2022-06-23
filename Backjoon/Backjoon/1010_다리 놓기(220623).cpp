#include <stdio.h>

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

	int temp = binomialNumbers(30, 15);

	for (int i = 0; i < t; ++i)
	{
		int n, k;
		scanf_s("%d %d", &n, &k);

		int result = binomialNumbers(k, n);

		printf("%d\n", result);
	}
	

	return 0;
}