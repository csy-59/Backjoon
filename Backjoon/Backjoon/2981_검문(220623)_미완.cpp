// # 문제 해석
// >> 앞에서 부터 공약수 비슷한 것을 구하여 출력하는 문제.
// 
// # 문제 알고리즘 구성
// [1번 알고리즘]
// >> 출력이 증가하는 순서이어야 하는만큼, 2부터 찾아간다.
// >> 2 ~ 최소값까지 비교한다.
// >> 마지막으로 나머지 숫자에서 최소값을 빼고 그 중에서 공약수가 있는지 확인한다.
// !오류!
// >> 시간 초과... O(n^2)이다...
// 
// [2번 알고리즘]
// >> 입력 받은 데이터를 모두 더한 다음에 검색 값 * data.size()만큼 나눈 나머지를 size()로 나눈 것의 나머지가 0이면 된다.
// >> 아마... 제발...
// !오류!
// >> 멍청한 생각이었다.
// >> ... * data.size() % data.size()는 무조건 0일 수밖에 없다.
// 
// [3번 알고리즘]
// >> M이 아닌 수를 모아 두고, 이에 해당하는 배수는 확인하지 않는다!!!
// !오류!
// >> 당연히 그럼 시간이 더 많이 들지 멍청아
// 
// =============================================
//	교수님의 조언!: 점화식을 찾아서 DP(Dynamic Programming) 알고리즘을 사용하자!!
//		>> DP 알고리즘 중 momeization.
//			>> 연산 시 최적이라고 생각하는 값을 저장해두고,
//			>> 다음 연산 시 해당 최적값을 가져와 사용한다.
// =============================================
//	.... ㅈ..점화식을 찾자..
// ## 유클리드 호제법
//	>> a = b*q + r 인 경우, gcd(a, b) == gcd(b,r) 이다(*gcd는 최대공약수를 의미)
//	>> ex. 12345 = 1234*10 + 5, 1234 = 5*246 + 4, 5 = 4*1 + 1; 4 = 1 * 4 + 0
//			gcd(12345, 1234) == gcd(1234, 5) = gcd(5,1) = gcd(1,0) = 1
//

#include <stdio.h>
#include <vector>

bool result[500000001] = { false };
int main()
{
	int n;
	scanf_s("%d", &n); 

	std::vector<long> nums;
	long temp, max = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf_s("%ld", &temp);
		nums.push_back(temp);

		if (temp > max)
		{
			max = temp;
		}
	}

	for (int i = max / 2 + 1; i > 0; --i)
	{
		if (result[i] == true)
		{
			continue;
		}

		bool isM = true;
		long left = nums[0] % i;

		for (auto iter = ++nums.begin(); iter != nums.end(); ++iter)
		{
			if (*iter % i != left)
			{
				isM = false;
				break;
			}
		}

		if (isM)
		{
			result[i] = true;
			result[nums[0] / i] = true;
		}
	}

	for (int i = 0; i < 500000001; ++i)
	{
		if (result[i] == true)
		{
			printf("%d ", i);
		}
	}

	return 0;
}