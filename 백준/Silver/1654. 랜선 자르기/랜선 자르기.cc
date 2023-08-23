#include <iostream>
#include <algorithm>
using namespace std;
long long int Array[1000001]; // 1~max(Array[i])까지 이분탐색하면서 결과찾기
int main()
{
	long long int N, K;
	long long int max = -1;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> Array[i];
		max = (max < Array[i]) ? Array[i] : max;
	}
	long long result = 0, temp = 0;
	long long int min = 1, mid = (min + max) / 2;

	while (true)
	{
		if (min > max) break;

		mid = (min + max) / 2;
		for (int i=0; i<N; i++)
		{
			if ((Array[i] / mid) > 0)
				temp += (Array[i] / mid);
		}
		if (temp >= K)
		{
			if (result < mid)
				result = mid;
			min = mid + 1;

		}
		else
		{
			max = mid - 1;
		}
		temp = 0;

		

	}
	cout << result;


	
}