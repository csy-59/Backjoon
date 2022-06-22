// # ���� �м�
// >> ����� ���ϴ� �Ͱ� ����.
//	>> ��, 1 1 2 2 3 3 4 4  >> 0 0 2 2 4 4 6 6 �̷��� ���
// 
// # ������ �Է�
// >> �ϳ��� �������� �ִ� ũ��: -1000,000,000 ~ 1000,000,000 >> long long ���
//	>> �� �����ʹ� �ߺ� �� �� ������, �������� ������ ũ�� �߿����� �ʴ�.
//		>> look up table? >> ������ �ϳ��� ũ�Ⱑ �ʹ� ŭ���� ������� �ʴ´�.
//		>> vector.push_back()? >> ������ ��, �ش� �������� �ε��� ���� �� ���� �ȴ�.
//			>> ���� �޾ƿ� �����ʹ� ��� �ʿ���. ������ ���� vector�� �� �ʿ��ϴ�.
//				>> �޸𸮰� ����Ǵ� ������ �� �ִ�.
//				>> �ٸ� �޸� ���� �����ϱ� ���� for�� �ϳ� �� ���ٸ� ���� �ð����� ����
//					>> ��� �ּ��ε�...?
//			>> �ٸ� �ߺ��� ������ ��쿡 ���� ���� ó�� �־�� �Ѵ�.
//			>> cmp���� �����͸� �����ϴ� ����...?: �̰� sort�� �ǵ��� �ƴ� �� ����...
// 
// *�������� ��� 1: ������̺�	>> �޸� ���� �Ѿ X
// *�������� ��� 2: �ܼ� ������ �Է� ��, �ϳ��� ���� >> �ð������� �ָ�.... -
// *�������� ��� 3: vector�� sort�� �̿� >> ���� �մ��� �� O
// 
// # ������� �˰���
// 1. �����͸� �Է¹޴´�. (����� ���� original, ������ ���� sorted);
//		* sorted �����ʹ� pair<int, int>�� vector. (������, �ش� �������� ����)
// 2. �Է� ���� �����͸� �����Ѵ�.
//		* sorted �����͸� ����
// 3. ����� ����Ѵ�.
//		>> original�� �����Ͽ�, �ش� ������ 
//

// # Ǯ�� �ı�
// >> �ڷᱸ���� �˰����� �߿伺�� �� �ٽ� ������.
//	>> ��û�ϰ� �׳� �����Ͽ� ���ϴ� �͵� ���������
//		Ȯ���� �̺��� �� ȿ������ ����� ������ �ٽ� �����ϴ� ���� ���ٴ� ������ �����.
//	>> �� �ڷᱸ���� �˰����� ������ �����ؼ� ���߿��� �� ���� �˰������� �ٽ� Ǯ��ڴ�.
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