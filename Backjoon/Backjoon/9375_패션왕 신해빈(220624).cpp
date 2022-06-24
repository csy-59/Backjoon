#include <iostream>
#include <utility>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;
	
	int clothCount;
	string nameTemp;
	vector<pair<string, int>> cloths;
	for (int i = 0; i < t; ++i)
	{
		cin >> clothCount;

		cloths.clear();
		for (int i = 0; i < clothCount; ++i)
		{
			cin >> nameTemp >> nameTemp;

			bool isNotThereCloth = true;
			for (int i = 0; i < cloths.size(); ++i)
			{
				if (cloths[i].first.compare(nameTemp) == 0)
				{
					++cloths[i].second;
					isNotThereCloth = false;
					break;
				}
			}

			if (isNotThereCloth)
			{
				cloths.push_back({ { nameTemp }, 2 });
			}
		}

		int result = 1;
		for (int i = 0; i < cloths.size(); ++i)
		{
			result *= cloths[i].second;
		}
		--result;

		cout << result << "\n";
	}


	return 0;
}