#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

bool isBrokenKey[11] = { false };
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	int broken;
	for (int i = 0; i < k; ++i)
	{
		scanf("%d", &broken);
		isBrokenKey[broken] = true;
	}

	// n보다 크면서 n과 가장 가까운 수 구하기 & n보다 작으면서 n과 가장 가까운 수 구하기
	int temp = n, ten = 1;
	int max = 0, min = 0;
	int result = 0;
	while (temp > 0)
	{
		if (isBrokenKey[temp % 10] == false)
		{
			max+=temp%10
		}
		else
		{
			//max 찾기
			for (int i)

				//min 찾기

		}
	}

	return 0;
}