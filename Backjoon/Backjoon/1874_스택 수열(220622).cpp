// # ���� �м�
// >> pop�� push�� �̿��ؼ� �ش� ����� ����� �� ���� �� Ȯ��.
//
// # ���� �ؼ�
// >> push pop�� ���� ���� ���󰣴�.
// 
// # ���� �ذ�
// >> vector�� push pop�� ���� ������� ���� �����ϰ� ����� ť ���·�
//

#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
	int n;
	scanf_s("%d", &n);

	int temp;
	vector<char> result;
	vector<int> inStack;
	inStack.push_back(0);
	vector<int> outStack;
	int pushNum = 1;

	bool isNotPossible = false;
	for (int i = 0; i < n; ++i)
	{
		scanf_s("%d", &temp);

		if (isNotPossible)
		{
			continue;
		}

		while (inStack.back() < temp)
		{
			inStack.push_back(pushNum);
			result.push_back('+');
			++pushNum;
		}

		outStack.push_back(inStack.back());
		inStack.pop_back();
		if (outStack.back() != temp)
		{
			isNotPossible = true;
		}
		result.push_back('-');
	}

	if (isNotPossible)
	{ 
		printf("NO\n");
	}
	else
	{
		for (char ch : result)
		{
			printf("%c\n", ch);
		}
	}

	return 0;
}