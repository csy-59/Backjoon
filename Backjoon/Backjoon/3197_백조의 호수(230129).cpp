/*
* [������ ȣ��]
* - ������ �ִ� ȣ��
* - �Ϸ簡 ���� ������ �ֺ��� ���� �ִ� ������ ��´�
* - ��ĥ�� ������ ������ ���� �� �ִ°�
* 
* <�� ����>
* - BFS�� ���� ��� �� ���
* - A* �˰������� ������ ���� �� �ִ��� �Ǵ�
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

struct Point
{
	int x;
	int y;
};

Point S1, S2;
int r, c, i, j;
char lake[1500][1502];

void BFS()
{

}

bool AStar()
{
	priority_queue<Point> openList;

}

int main()
{
	scanf("%d %d", &r, &c);

	for (i = 0; i < r; ++i)
	{
		scanf("%s", &lake[i]);
	}

	return 0;
}