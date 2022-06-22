// # 문제 분석
// >> 등수를 구하는 것과 유사.
//	>> 즉, 1 1 2 2 3 3 4 4  >> 0 0 2 2 4 4 6 6 이렇게 출력
// 
// # 데이터 입력
// >> 하나의 데이터의 최대 크기: -1000,000,000 ~ 1000,000,000 >> long long 사용
//	>> 각 데이터는 중복 될 수 있지만, 데이터의 개수가 크게 중요하지 않다.
//		>> look up table? >> 데이터 하나의 크기가 너무 큼으로 사용하지 않는다.
//		>> vector.push_back()? >> 정렬한 후, 해당 데이터의 인덱스 값이 곧 답이 된다.
//			>> 원래 받아온 데이터는 계속 필요함. 정렬을 위한 vector가 또 필요하다.
//				>> 메모리가 낭비되는 방향일 수 있다.
//				>> 다만 메모리 낭비를 제한하기 위해 for을 하나 더 쓴다면 실행 시간에서 낭비
//					>> 요게 최선인듯...?
//			>> 다만 중복된 숫자인 경우에 대한 예외 처리 있어야 한다.
//			>> cmp에서 데이터를 수정하는 방향...?: 이건 sort의 의도가 아닌 것 같음...
// 
// *생각나는 방법 1: 룩업태이블	>> 메모리 제한 넘어감 X
// *생각나는 방법 2: 단순 데이터 입력 후, 하나씩 연산 >> 시간적으로 애매.... -
// *생각나는 방법 3: vector와 sort를 이용 >> 가장 합당한 듯 O
// 
// # 결론적인 알고리즘
// 1. 데이터를 입력받는다. (출력을 위한 original, 연산을 위한 sorted);
//		* sorted 데이터는 pair<int, int>형 vector. (데이터, 해당 데이터의 개수)
// 2. 입력 받은 데이터를 정렬한다.
//		* sorted 데이터를 정렬
// 3. 결과를 출력한다.
//		>> original에 접근하여, 해당 번수의 
//

// # 풀이 후기
// >> 자료구조와 알고리즘의 중요성을 또 다시 느꼈다.
//	>> 멍청하게 그냥 대입하여 구하는 것도 방법이지만
//		확실히 이보다 더 효율적인 방법은 없는지 다시 생각하는 것이 좋다는 생각이 들었다.
//	>> 더 자료구조와 알고리즘을 열심히 공부해서 나중에는 더 나은 알고리즘으로 다시 풀어보겠다.
//
#include <stdio.h>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;

int binarySearch(vector<long>::iterator begin, vector<long>::iterator end, long value)
{
	auto originalBegin = begin;
	int pivot = (end - begin) / 2;

	long cmpValue;
	while (begin < end)
	{
		cmpValue = *(begin + pivot);

		if (cmpValue == value)
		{
			return (begin + pivot) - originalBegin;
		}
		else if (cmpValue < value)
		{
			begin = begin + pivot + 1;
		}
		else if (cmpValue > value)
		{
			end = begin + pivot - 1;
		}

		pivot = (end - begin) / 2;
	}

	return (begin + pivot) - originalBegin;
}

int main()
{
	int n;
	scanf_s("%d", &n);

	long temp;
	vector<long> original;
	vector<long> sorted;
	for (int i = 0; i < n; ++i)
	{
		scanf_s("%ld", &temp);
		original.push_back(temp);
		sorted.push_back(temp);
	}

	sort(sorted.begin(), sorted.end());
	sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

	for (int i = 0; i < original.size(); ++i)
	{
		printf("%d ", binarySearch(sorted.begin(), sorted.end(), original[i]));
	}

	return 0;
}