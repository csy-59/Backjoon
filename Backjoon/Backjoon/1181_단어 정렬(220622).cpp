#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const string& a, const string& b)
{
	if (a.size() != b.size())
	{
		return a.size() < b.size();
	}
	else
	{
		return strcmp(a.c_str(), b.c_str()) < 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int stringCount;
	cin >> stringCount;

	string temp;
	vector<string> stringArr;
	for (int i = 0; i < stringCount; ++i)
	{
		cin >> temp;

		if (find(stringArr.begin(), stringArr.end(), string(temp)) == stringArr.end())
		{
			stringArr.push_back({temp});
		}
	}

	sort(stringArr.begin(), stringArr.end(), cmp);

	for (int i = 0; i < stringArr.size(); ++i)
	{
		cout << stringArr[i] << "\n";
	}

	return 0;
}