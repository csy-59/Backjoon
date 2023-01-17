#include <stdio.h>
#include <algorithm>

int arr[1000] = { 0 };
int main()
{
	int n, k;
	scanf_s("%d %d", &n, &k);

	for (int i = 0; i < n; ++i)
	{
		scanf_s("%d", &arr[i]);
	}

	std::sort(arr, arr + n);
	printf("%d", arr[n - k ]);
}