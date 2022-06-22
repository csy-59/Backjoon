#include <stdio.h>
#include <cmath>
using namespace std;

int width, height, x, y, playerCount;

bool isInfirstCircle(int pX, int pY)
{
	return pow((pX - x), 2) + pow((pY - y - height / 2), 2) <= (height / 2) * (height / 2);
}

bool isInSquare(int pX, int pY)
{
	if (pX >= x && pX <= x + width && pY >= y && pY <= y + height)
	{
		return true;
	}

	return false;
}

bool isInSecondCircle(int pX, int pY)
{
	return pow((pX - x - width), 2) + pow((pY - y - height / 2), 2) <= (height / 2) * (height / 2);
}

int main()
{
	scanf_s("%d %d %d %d %d", &width, &height, &x, &y, &playerCount);

	int px, py;
	int result = 0;
	for (int i = 0; i < playerCount; ++i)
	{
		scanf_s("%d %d", &px, &py);

		if (isInfirstCircle(px, py) || isInSquare(px, py) || isInSecondCircle(px, py))
		{
			++result;
		}
	}

	printf("%d", result);

	return 0;
}