#include <iostream>
using namespace std;
#define MAX 1002
#define MOD 10007
int n, dp[MAX][11]; // 0 = 10
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= 10; i++)
		dp[1][i] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			for (int k = 1; k <= j; k++)
			{
				dp[i][j] += (dp[i-1][k] % MOD);
				dp[i][j] %= MOD;
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= 10; i++)
	{
		res += dp[n][i];
		res %= MOD;
	}
	cout << res % MOD;
}
