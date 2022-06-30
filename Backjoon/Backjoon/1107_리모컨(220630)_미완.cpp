#include <iostream>
#include <cmath>
using namespace std;

int target;
int m;
bool broken[10] = { false };
int result = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> target;
	int tTemp = target;
	int size = 0;
	while (tTemp > 0)
	{
		++size;
		tTemp /= 10;
	}

	cin >> m;

	int temp;
	for (int i = 0; i < m; ++i)
	{
		cin >> temp;
		broken[temp] = true;
	}

	return 0;
}