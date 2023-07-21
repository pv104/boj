#include <iostream>
#include <vector>
#include <algorithm>
#define START first
#define WEIGHT second
#define MAX 25
using namespace std;
vector <pair<int,int>> v[MAX]; // <시작,돈>, 작업이 끝나는 날짜가 인덱스
vector <int> dp(MAX); // dp[i] = dp[1]~dp[i-1]까지의 최대 이익
int n, t, p;
void input()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> t >> p;
		int ED = t + i - 1;
		v[ED].push_back({ i,p });
	}
}
int solve()
{
	for (int i = 1; i <= n; i++)
	{
			for (auto& k : v[i])
			{
				// 직전 값(현재 최대값)의 인덱스를 찾음
				auto it = lower_bound(dp.begin(), dp.begin() + i, dp[i - 1]);
				auto idx = it - dp.begin();
				// 인덱스보다 i날의 작업 시작일이 큰 경우에는 추가할 수 있음
				if (idx < k.START)
					dp[i] = max(dp[i], dp[idx] + k.WEIGHT);
				// 인덱스보다 i날의 작업 시작일이 같거나 작은 경우에는 추가할 수 없음
				// dp[idx]에 작업이 끝나고 바로 시작할 수 없고, 
				// 작업 시작일이 더 작은 경우에는 해당 작업을 선택하는게 손해
				else
					dp[i] = max(dp[i], max(dp[idx],dp[k.START - 1] + k.WEIGHT));
			}
			// 해당 작업일에 종료되는 작업이 없는 경우
		if(dp[i] == 0)
		dp[i] = dp[i-1];
	}

	return dp[n];
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	cout << solve();
	return 0;
}