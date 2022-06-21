#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

int _count[10001] = { 0 };
int main()
{
	int n;
	scanf_s("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		int temp;
		scanf_s("%d", &temp);

		++_count[temp];
	}

	for (int i = 0; i <= 10000; ++i)
	{
		for (int j = 0; j < _count[i]; ++j)
		{
			printf("%d\n", i);
		}
	}

	return 0;
}