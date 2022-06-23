#include <stdio.h>

int min(int n, int m)
{
	return (n < m) ? n : m;
}

int maxFactor(int n, int m)
{
	for (int i = min(n, m); i >= 1; --i)
	{
		if (n % i == 0 && m % i == 0)
		{
			return i;
			break;
		}
	}
}

int main()
{
	int t;
	scanf_s("%d", &t);

	for (int i = 0; i < t; ++i)
	{
		int n, m;
		scanf_s("%d %d", &n, &m);

		printf("%d\n", n * m / maxFactor(n, m));
	}

	return 0;
}