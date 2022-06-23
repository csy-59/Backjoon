#include <stdio.h>

int main()
{
	int n, m;

	while (true)
	{
		scanf_s("%d %d", &n, &m);

		if (n == 0 && m == 0)
		{
			break;
		}

		if (m % n == 0)
		{
			printf("factor\n");
		}
		else if (n % m == 0)
		{
			printf("multiple\n");
		}
		else
		{
			printf("neither\n");
		}
	}

	return 0;
}