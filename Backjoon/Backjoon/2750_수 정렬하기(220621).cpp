#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int arr[1001] = { 0 };

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	std::sort(&arr[0], &arr[n]);

	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << "\n";
	}
}