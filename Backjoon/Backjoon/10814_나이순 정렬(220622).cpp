#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

//ù��° �õ�: vector�� pair >> ��ȿ����... �ð��� �ʹ� ���� �ɸ���!!
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
	vector<string> clientsNames; //�̸�
	vector<pair<int, int>> clients; //����, ���� ����
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