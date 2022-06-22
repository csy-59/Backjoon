// # 문제 분석
// >> pop과 push를 이용해서 해당 결과를 출력할 수 있을 지 확인.
//
// # 문제 해석
// >> push pop을 통해 논리를 따라간다.
// 
// # 문제 해결
// >> vector로 push pop을 통해 결과값을 따로 저장하고 결과를 큐 형태로
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