#include <stdio.h>

int min(int n, int m)
{
	return (n < m) ? n : m;
}

int main()
{
	int n, m;
	scanf_s("%d %d", &n, &m);

	for (int i = min(n, m); i >= 1; --i)
	{
		if (n % i == 0 && m % i == 0)
		{
			printf("%d\n%d\n", i, n * m / i);
			break;
		}
	}

	return 0;
}