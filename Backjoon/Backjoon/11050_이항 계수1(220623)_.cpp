#include <stdio.h>

int facArr[11] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320,362880,3628800 };

int main()
{
	int n, k;
	scanf_s("%d %d", &n, &k);

	int result;
	if (k < 0 || k > n)
	{
		result = 0;
	}
	else
	{
		result = facArr[n] / (facArr[k] * facArr[n - k]);
	}

	printf("%d", result);

	return 0;
}