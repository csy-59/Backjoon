// # 풀이 후기
// >> 간단한 문제처럼 보였는데, 생각보다 시간이 오래 걸려서 놀랐다.
//		찾아보니 bitset을 사용하여 더 빠르게 푼 사람이 있다는 것을 발견했다.
//		저번 스터디 때 배운 bitmap이라는 개념을 실제로 사용하는 코드를 본 건 처음이라 놀라웠다.
//		>> 다음부터는 더 적극적으로 익히 개념을 사용해보는 것이 좋을 것 같다.
//

//첫번째 방법: 벡터와 이진 탐색
/*
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	scanf_s("%d", &n);

	long temp;
	vector<long> cards;
	for (int i = 0; i < n; ++i)
	{
		scanf_s("%d", &temp);
		cards.push_back(temp);
	}
	
	sort(cards.begin(), cards.end());

	int m;
	scanf_s("%d", &m);

	for (int i = 0; i < m; ++i)
	{
		scanf_s("%d", &temp);
		printf("%d ", binary_search(cards.begin(), cards.end(), temp));
	}

	return 0;
}
*/

//두번째 방법: bitset 사용 >> 이해불가....ㅠㅠ
#include<cstdio>
#include<cctype>
#include<bitset>
#define gc getchar_unlocked
inline int readint() {
	int r = 0, g = 0;
	char c = gc();
	while (c < 33) c = gc();
	if (c == '-') g = 1, c = gc();
	while (isdigit(c)) {
		r = r * 10 + (c & 15);
		c = gc();
	}
	return g ? -r : r;
}
int n, x;
std::bitset<20000001> bs;
int main() {
	n = readint();
	while (n--) {
		bs[readint() + 10000000] = 1;
	}
	n = readint();
	while (n--) {
		printf("%d ", bs.test(readint() + 10000000));
	}
}