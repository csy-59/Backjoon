#include <stdio.h>
using namespace std;

int facLastNumArr[501] = {1,1,2,6,24,};
int facZeroNumArr[501] = { 0 };
int zeroFactorial(int num)
{
	if (facLastNumArr[num] != -1)
	{ 
		return facLastNumArr[num];
	}

	int temp = zeroFactorial(num - 1) * num;
	facZeroNumArr[num] = facZeroNumArr[num - 1];
	while (temp % 10 == 0)
	{
		++facZeroNumArr[num];
		facLastNumArr[num] = temp / 10;

		temp /= 10;
	}

	facLastNumArr[num] = temp % 100000;

	return facLastNumArr[num];
}

int main()
{
	for (int i = 5; i < 501; ++i)
	{
		facLastNumArr[i] = -1;
	}

	int n;
	scanf_s("%d", &n);

	zeroFactorial(n);
	printf("%d", facZeroNumArr[n]);

	return 0;
}