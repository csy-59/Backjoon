#include <iostream>
using namespace std;

long long countTwo(long long num)
{
	long long result = 0;

	int times = 1;
	while (num > 0)
	{
		result += num << times;
		++times;
	}

	return result;
}
long long countN(long long num, int n)
{
	long long result = 0;

	long long temp = n;
	while (temp <= num)
	{
		result += num / temp;
		temp *= n;
	}

	return result;
}

long long countTen(long long two, long long five)
{
	if (two > five)
	{
		return five;
	}
	return two;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long n, m;
	cin >> n >> m;

	if (n - m > m)
	{
		m = n - m;
	}

	unsigned long nmZero = countTen(countTwo(n - m), countN(n - m, 5));
	unsigned long mZero = countTen(countTwo(m), countN(m, 5));
	unsigned long nZero = countTen(countTwo(n), countN(n, 5));

	cout << nZero - mZero - nmZero;


	return 0;
}