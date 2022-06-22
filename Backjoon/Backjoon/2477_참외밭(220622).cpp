#include <stdio.h>
using namespace std;

int main()
{
	int meterCount;
	scanf_s("%d", &meterCount);

	int width_max = 0, width_min = 500;
	int height_max = 0, height_min = 500;

	int dirList[6] = { 0 };
	int meter[6] = { 0 };
	int pre_width, pre_height;
	for (int i = 0; i < 6; ++i)
	{
		scanf_s("%d %d", &dirList[i], &meter[i]);

		if (i % 2 == 0)
		{
			if (width_max < meter[i])
			{
				width_max = meter[i];
			}
		}
		else
		{
			if (height_max < meter[i])
			{
				height_max = meter[i];
			}
		}
	}

	//빠져야 하는 값 계산
	for (int i = 0; i <= 5; ++i)
	{
		int index1 = i;
		int index2 = (i + 2) % 6;
		if (dirList[i] == dirList[(i + 2) % 6] && dirList[(i + 1) % 6] == dirList[(i + 3) % 6])
		{
			width_min = meter[(i + 1) % 6];
			height_min = meter[(i + 2) % 6];
			break;
		}
	}

	long area = ((height_max * width_max) - (height_min * width_min));
	printf("%ld", area * meterCount);

	return 0;
}