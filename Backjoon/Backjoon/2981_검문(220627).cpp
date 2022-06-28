// # ���� �ؼ�
// >> �տ��� ���� ����� ����� ���� ���Ͽ� ����ϴ� ����.
// 
// # ���� �˰��� ����
// [1�� �˰���]
// >> ����� �����ϴ� �����̾�� �ϴ¸�ŭ, 2���� ã�ư���.
// >> 2 ~ �ּҰ����� ���Ѵ�.
// >> ���������� ������ ���ڿ��� �ּҰ��� ���� �� �߿��� ������� �ִ��� Ȯ���Ѵ�.
// !����!
// >> �ð� �ʰ�... O(n^2)�̴�...
// 
// [2�� �˰���]
// >> �Է� ���� �����͸� ��� ���� ������ �˻� �� * data.size()��ŭ ���� �������� size()�� ���� ���� �������� 0�̸� �ȴ�.
// >> �Ƹ�... ����...
// !����!
// >> ��û�� �����̾���.
// >> ... * data.size() % data.size()�� ������ 0�� ���ۿ� ����.
// 
// [3�� �˰���]
// >> M�� �ƴ� ���� ��� �ΰ�, �̿� �ش��ϴ� ����� Ȯ������ �ʴ´�!!!
// !����!
// >> �翬�� �׷� �ð��� �� ���� ���� ��û��
// 
// =============================================
//	�������� ����!: ��ȭ���� ã�Ƽ� DP(Dynamic Programming) �˰����� �������!!
//		>> DP �˰��� �� momeization.
//			>> ���� �� �����̶�� �����ϴ� ���� �����صΰ�,
//			>> ���� ���� �� �ش� �������� ������ ����Ѵ�.
// =============================================
//	.... ��..��ȭ���� ã��..
// ## ��Ŭ���� ȣ����
//	>> a = b*q + r �� ���, gcd(a, b) == gcd(b,r) �̴�(*gcd�� �ִ������� �ǹ�)
//	>> ex. 12345 = 1234*10 + 5, 1234 = 5*246 + 4, 5 = 4*1 + 1; 4 = 1 * 4 + 0
//			gcd(12345, 1234) == gcd(1234, 5) = gcd(5,1) = gcd(1,0) = 1
// 
// [4�� �˰���]
// -��-���� �����̴ּ�...
// > �Է��� 4�� A B C D(�ּҰ�)�� �ִٸ�
// > q(a)+r / q(b)+r / q(c)+r / q(d)+r �̶�� �ǹ��̴�.
// > ��, ��� ���� ���̴� ������ ���� �ȴ�.
//		q(a-b) , a(b-c), a(c-d), q(a-c), q(b-d), q(a-d), ...
//		���� �ᱹ ��� ���� ������� ��� ����ϸ� �ȴ�.
// 
// ## Ǯ�� �ı�
// >> ��~ �ٽô� ��Ǯ��~ ���� �˳� ����~~
// >> �峭�̰� ��¥ ���� �׾�� �ؾ߰ڴٴ� ������ �����.
// >> ������ ȯ���� �ѹ��� Ǫ�� �� ���� �ణ �λ��� ȸ�ǰ���...
// >> ���� ���� õ���ǰ� �ʹ� ����...
// >> ���󿡼� �����ϰ� �ѹ��ϰ� �߱��� ���ϴ� ��� ���� �ű��ؤ�....
//

#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>

long gcd(int a, int b)
{
	if (b == 1 || b == 0)
	{
		return a;
	}

	if (a % b == 0)
	{
		return b;
	}

	return gcd(b, a % b);
}

int main()
{
	int n;
	scanf_s("%d", &n); 

	std::vector<long> nums;
	long temp;
	for (int i = 0; i < n; ++i)
	{
		scanf_s("%ld", &temp);
		nums.push_back(temp);
	}

	long min = 1000000001, max = -1;
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			long tempDiffer = abs(nums[i] - nums[j]);
			
			if (tempDiffer < min && tempDiffer != 0)
			{
				min = tempDiffer;
			}

			if (tempDiffer > max)
			{
				max = tempDiffer;
			}
		}
	}

	long result = gcd(max, min);

	if (min == 1000000001)
	{
		result = nums[0];
	}

	std::vector<long> resultList;

	for (long i = 2; i <= sqrt(result); ++i)
	{
		if (result % i == 0)
		{
			resultList.push_back(i);
			if (i != (result / i))
			{
				resultList.push_back(result/i);
			}
		}
	}

	resultList.push_back(result);

	std::sort(resultList.begin(), resultList.end());

	for (int i = 0; i < resultList.size(); ++i)
	{
		printf("%d ", resultList[i]);
	}

	return 0;
}