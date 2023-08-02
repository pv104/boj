#include <iostream>
using namespace std;
#define MAX 1002
int dp[MAX];
int P[MAX];
int n;
void input()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> P[i];
}
int solve()
{
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (i % j == 0)
			{
				dp[i] = max(dp[i], dp[j] * (i / j));
			}
			else
				dp[i] = max(dp[i], dp[j] * (i / j) + dp[i % j]);

		}
		dp[i] = max(dp[i],P[i]);
	}
	return dp[n];
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	cout << solve();
}