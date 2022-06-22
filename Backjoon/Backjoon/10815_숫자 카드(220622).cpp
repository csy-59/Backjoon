// # Ǯ�� �ı�
// >> ������ ����ó�� �����µ�, �������� �ð��� ���� �ɷ��� �����.
//		ã�ƺ��� bitset�� ����Ͽ� �� ������ Ǭ ����� �ִٴ� ���� �߰��ߴ�.
//		���� ���͵� �� ��� bitmap�̶�� ������ ������ ����ϴ� �ڵ带 �� �� ó���̶� ������.
//		>> �������ʹ� �� ���������� ���� ������ ����غ��� ���� ���� �� ����.
//

//ù��° ���: ���Ϳ� ���� Ž��
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

//�ι�° ���: bitset ��� >> ���غҰ�....�Ф�
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