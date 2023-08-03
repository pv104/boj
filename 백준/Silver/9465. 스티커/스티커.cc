#include <iostream>
using namespace std;	
#define MAX 100002
int sticker[3][MAX];
int dp[3][MAX];
int n;
void input()
{
	cin >> n;
	for (int i = 1; i <= 2; i++)
		for (int j = 1; j <= n; j++)
			cin >> sticker[i][j];
}
int solve()
{
	dp[1][1] = sticker[1][1];
	dp[2][1] = sticker[2][1];
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= 2; j++)
		{
			if (j == 1)
			{
				dp[j][i] = max(dp[j][i - 2], max(dp[j + 1][i - 1],dp[j+1][i-2])) + sticker[j][i];

			}
			else
			{
				dp[j][i] = max(dp[j][i - 2], max(dp[j-1][i-2],dp[j - 1][i - 1])) + sticker[j][i];
				
			}
		}
	}

	return max(dp[1][n], dp[2][n]);
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		input();
		cout << solve() << "\n";
		for (int i=1; i<=n; i++)
			for (int j = 1; j <= 2; j++)
			{
				dp[j][i] = sticker[j][i] = 0;
			}
	}
}