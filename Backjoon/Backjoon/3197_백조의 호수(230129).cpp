/*
* [백조의 호수]
* - 얼음이 있는 호수
* - 하루가 지날 때마다 주변에 물이 있는 얼음은 녹는다
* - 며칠이 지나야 백조가 만날 수 있는가
* 
* <내 생각>
* - BFS로 얼음 녹는 걸 계산
* - A* 알고리즘으로 백조가 만날 수 있는지 판단
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