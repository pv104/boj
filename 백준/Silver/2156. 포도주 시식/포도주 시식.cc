#include <iostream>
using namespace std;
#define MAX 10003
int n;
int dp[MAX], grape[MAX]; // dp[i]
void input()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> grape[i];
	}
}
int solve()
{
	int res = 0;
	dp[1] = grape[1];
	dp[2] = grape[1] + grape[2];
	dp[3] = max(dp[2], max(grape[1] + grape[3], grape[2] + grape[3]));
	for (int i = 4; i <= n; i++)
	{
		dp[i] = max(dp[i-1], max(dp[i - 3] + grape[i - 1] + grape[i], dp[i - 2] + grape[i]));
	}

	for (int i = 1; i <= n; i++)
	{
		res = max(dp[i], res);
	}
	return res;
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	cout << solve();
}