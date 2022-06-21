#include <algorithm>
#include <iostream>
using namespace std;

int arr[1000001] = { 0 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	std::sort(&arr[0], &arr[n]);

	for (int i = 0; i < n; ++i)
	{
		cout << arr[i]<<"\n";
	}

	return 0;
}