#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

//첫번째 시도: vector와 pair >> 비효율적... 시간이 너무 오래 걸린당!!
bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.first != b.first)
	{
		return a.first < b.first;
	}
	else
	{
		return a.second < b.second;
	}
}

int main()
{
	int n;
	cin >> n;

	int age;
	string name;
	vector<string> clientsNames; //이름
	vector<pair<int, int>> clients; //나이, 가입 순서
	for (int i = 0; i < n; ++i)
	{
		cin >> age >> name;
		clients.push_back({ age, i });
		clientsNames.push_back({ name });
	}

	sort(clients.begin(), clients.end(), cmp);

	for (int i = 0; i < clients.size(); ++i)
	{
		cout << clients[i].first << " " << clientsNames[clients[i].second] << "\n";
	}

	return 0;
}