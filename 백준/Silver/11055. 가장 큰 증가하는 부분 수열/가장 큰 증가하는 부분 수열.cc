#include <iostream>
using namespace std;
#define MAX 1002
int dp[MAX], val[MAX];
int n;
void input()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> val[i];
}
int solve()
{
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (val[j] < val[i])
				dp[i] = max(dp[i], dp[j]);
		}
		dp[i] += val[i];
	}
	for (int i = 1; i <= n; i++)
		res = max(res, dp[i]);
	return res;
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	cout << solve();
}