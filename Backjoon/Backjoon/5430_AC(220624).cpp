#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <deque>
#include <string.h>
using namespace std;

char word[100010];		
char temp[10000010];
int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; ++i)
	{
		word[0] = '\0';
		scanf("%s", word);

		int queCount;
		scanf("%d", &queCount);

		temp[0] = '\0';
		scanf("%s", temp);

		//데이터 처리
		//for (int i = 0; i < strlen(temp) - 1; ++i)
		//{
		//	temp[i] = temp[i + 1];
		//}
		//temp[strlen(temp) - 2] = NULL;
		
		deque<int> queue;
		temp[0] = ',';
		temp[strlen(temp) - 1] = ',';
		char* pos = strtok(temp, ",");
		while (pos != nullptr)
		{
			queue.push_back(atoi(pos));
			pos = strtok(NULL, ",");
		}

		//해당 데이터로 결과 출력
		bool isReversed = false;
		bool isError = false;
		for (int i = 0; i < strlen(word); ++i)
		{
			switch (word[i])
			{
			case 'R':
				isReversed = !isReversed;
				break;
			case 'D':
				if (isReversed)
				{
					if (queue.empty())
					{
						isError = true;
						break;
					}
					else
					{
						queue.pop_back();
					}
				}
				else
				{
					if (queue.empty())
					{
						isError = true;
						break;
					}
					else
					{
						queue.pop_front();
					}
				}
				break;
			}

			if (isError)
			{
				break;
			}
		}

		if (isError)
		{
			printf("error\n");
		}
		else
		{
			printf("[");
			if (!queue.empty())
			{
				if (isReversed)
				{
					printf("%d", queue.back());
					for (int i = queue.size() - 2; i >= 0; --i)
					{
						printf(",%d", queue[i]);
					}
				}
				else
				{
					printf("%d", queue.front());
					for (int i = 1; i < queue.size(); ++i)
					{
						printf(",%d", queue[i]);
					}
				}
			}
			printf("]\n");
		}
	}

	return 0;
}