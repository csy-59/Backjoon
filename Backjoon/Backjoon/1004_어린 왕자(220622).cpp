#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
using namespace std;

void littlePrince()
{
	pair<int, int> startPoint;
	pair<int, int> endPoint;
	cin >> startPoint.first >> startPoint.second >> endPoint.first >> endPoint.second;

	int pCount = 0;
	cin >> pCount;

	int result = 0;
	pair<int, int> planet;
	int planetRadius;
	for (int i = 0; i < pCount; ++i)
	{
		//행성 좌표 입력
		cin >> planet.first >> planet.second >> planetRadius;

		int entry = pow(startPoint.first - planet.first, 2) 
			+ pow(startPoint.second - planet.second, 2);
		int exit = pow(endPoint.first - planet.first, 2) 
			+ pow(endPoint.second - planet.second, 2);
		if (entry < planetRadius * planetRadius && !(exit < planetRadius * planetRadius))
		{
			++result;
		}
		else if(exit < planetRadius* planetRadius && !(entry < planetRadius* planetRadius))
		{
			++result;
		}
	}

	cout << result<<"\n";
}

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		littlePrince();
	}

	return 0;
}