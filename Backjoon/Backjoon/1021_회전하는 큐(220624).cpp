#include <stdio.h>
#include <deque>
#include <deque>
using namespace std;

int main()
{
	int queSize, n;
	scanf_s("%d %d", &queSize, &n);

	deque<int> queue;
	for (int i = 1; i <= queSize; ++i)
	{
		queue.push_back(i);
	}
	deque<int>::iterator cursor = queue.begin();

	int data = 0, preData;
	int result = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf_s("%d", &data);
		
		//데이터가 바로 있을 때
		if (*cursor == data)
		{
			queue.pop_front();
			cursor = queue.begin();
		}
		else
		{
			int count = 0;
			while (*cursor != data)
			{
				//2번 연산
				queue.push_back(queue.front());
				queue.pop_front();
				cursor = queue.begin();
				++count;
			}

			if (queue.size() - count > count)
			{
				result += count;
			}
			else
			{
				result += queue.size() - count;
			}

			queue.pop_front();
			cursor = queue.begin();
		}
	}

	printf("%d", result);

	return 0;
}