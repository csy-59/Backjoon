#include <stdio.h>

long long countN(long num, int n)
{
	long long result = 0;

	long long temp = n;
	while (temp <= num)
	{
		result += num / temp;
		temp *= n;
	}

	return result;
}

int main()
{
	long n, m;
	scanf_s("%d %d", &n, &m);

	if (n - m > m)
	{
		m = n - m;
	}

	long long nmZero = countN(n - m, 5);
	long long mZero = countN(m, 5);
	long long nZero = countN(n, 5);

	printf("%ld", nZero - mZero - nmZero);

	return 0;
}