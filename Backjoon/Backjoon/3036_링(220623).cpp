// # 문제 해석
// >> 
//

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
	int n;
	scanf_s("%d", &n);

	int first;
	scanf_s("%d", &first);

	int temp;
	for (int i = 0; i < n - 1; ++i)
	{
		scanf_s("%d", &temp);

		int fac = maxFactor(first, temp);
		printf("%d/%d\n", first / fac, temp / fac);
	}

	return 0;
}