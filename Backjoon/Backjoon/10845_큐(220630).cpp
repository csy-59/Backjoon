#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <deque>
#include <string.h>
using namespace std;

std::deque<int> q;
char temp[10] = "";
int n;

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%s", temp);

		if (strcmp(temp, "push") == 0)
		{
			int temp;
			scanf("%d", &temp);

			q.push_back(temp);
		}
		else if (strcmp(temp, "pop") == 0)
		{
			if (q.empty())
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", q.front());
				q.pop_front();
			}
		}
		else if (strcmp(temp, "size") == 0)
		{
			printf("%d\n", q.size());
		}
		else if (strcmp(temp, "empty") == 0)
		{
			printf("%d\n", q.empty());
		}
		else if (strcmp(temp, "front") == 0)
		{
			if (q.empty())
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", q.front());
			}
		}
		else if (strcmp(temp, "back") == 0)
		{
			if (q.empty())
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", q.back());
			}
		}
	}

	return 0;
}