#include <iostream>
using namespace std;
#define MAX 103
#define KMAX 100003
int nn, ww;
int dp[MAX][KMAX];
int w[MAX], c[MAX];
void init()
{
	cin >> nn >> ww;
	for (int i = 0; i < MAX; i++)
	{
		w[i] = c[i] = 0;
		for (int j = 0; j < KMAX; j++)
		{
			dp[i][j] = 0;
		}
	}
	for (int i = 1; i <= nn; i++)
	{
		cin >> w[i] >> c[i];
	}
}
int solve()
{
	for (int i = 1; i <= nn; i++)
	{
		for (int j = 1; j < w[i]; j++)
			dp[i][j] = dp[i - 1][j];
		for (int j = w[i]; j <= ww; j++)
		{
			dp[i][j] = max(dp[i-1][j], (dp[i-1][j - w[i]] + c[i]));
		}
	}
	return dp[nn][ww];
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	
		init();
		cout << solve();
}