#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
	int n;
	scanf_s("%d", &n);

	int data;
	char temp[10] = "";
	vector<int> queue;
	for (int i = 0; i < n; ++i)
	{
		scanf_s("%s", temp, sizeof(temp));

		if (strcmp(temp, "push"))
		{
			scanf_s("%d", &data);
			queue.insert(queue.begin(), data);
		}
		else if (strcmp(temp, "pop"))
		{
			if (queue.empty())
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", queue.back());
				queue.pop_back();
			}
		}
		else if (strcmp(temp, "size"))
		{
			printf("%d\n", (int) queue.size());
		}
		else if (strcmp(temp, "empty"))
		{
			if (queue.empty())
			{
				printf("1\n");
			}
			else
			{
				printf("0\n");
			}
		}
		else if (strcmp(temp, "front"))
		{
			if (!queue.empty())
			{
				printf("%d\n", queue.back());
			}
			else
			{
				printf("-1\n");
			}
		}
		else if (strcmp(temp, "back"))
		{
			if (!queue.empty())
			{
				printf("%d\n", queue.front());
			}
			else
			{
				printf("-1\n");
			}
		}
	}

	return 0;
}