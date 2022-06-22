// # 풀이 실패 후기: map에 대해 공부한 후 다시 도전하자

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	string temp;
	string s = "";
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		s += temp + "\n";
	}

	int result = 0;
	for (int i = 0; i < m; ++i)
	{
		cin >> temp;
		result += s.find(temp, temp.size()) == string::npos ? 0 : 1;
	}

	cout << result;

	return 0;
}