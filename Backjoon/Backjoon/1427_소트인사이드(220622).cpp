#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	long long number;
	scanf_s("%lld", &number);

	vector<int> numberlist;
	while (number > 0)
	{
		numberlist.push_back(number % 10);
		number /= 10;
	}

	std::sort(numberlist.begin(), numberlist.end());

	for (int i = numberlist.size() - 1; i >= 0; --i)
	{
		printf("%d", numberlist[i]);
	}
	printf("\n");

	return 0;
}