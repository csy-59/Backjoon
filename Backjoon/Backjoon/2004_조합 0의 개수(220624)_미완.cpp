#include <stdio.h>

unsigned long countN(unsigned long num, int n)
{
	int result = 0;

	unsigned long temp = n;
	while (temp <= num)
	{
		result += num / temp;
		temp *= n;
	}

	return result;
}

unsigned long countTen(unsigned long two, unsigned long five)
{
	if (two > five)
	{
		return five;
	}
	return two;
}

int main()
{
	long n, m;
	scanf_s("%d %d", &n, &m);

	if (n - m > m)
	{
		m = n - m;
	}

	unsigned long nmZero = countTen(countN(n - m, 2), countN(n - m, 5));
	unsigned long mZero = countTen(countN(m, 2), countN(m, 5));
	unsigned long nZero = countTen(countN(n, 2), countN(n, 5));

	printf("%ld", nZero - (mZero + nmZero));

	return 0;
}