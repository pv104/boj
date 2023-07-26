#include <iostream>
#include <vector>
using namespace std;
#define MAX 1002
#define W 32
#define VALUE first
#define COUNTS second
int Plum[MAX], dp[MAX][W];
int t, w;
void input()
{
	cin >> t >> w;
	for (int i = 1; i <= t; i++)
		cin >> Plum[i];
}
int solve()
{
	if (Plum[1] == 1)
		dp[1][0] = 1;
	else
		dp[1][1] = 1;
	for (int i = 2; i <= t; i++)
	{
		for (int j = 0; j <= w; j++)
		{
			if (j % 2 == 0)
			{
				if (Plum[i] == 1) // 1번 나무, j도 1번에 있음
				{
					if (j > 0)
						dp[i][j] = max(dp[i - 1][j] + 1, dp[i - 1][j - 1] + 1);
					else
						dp[i][j] = dp[i - 1][j] + 1;
				}
				else
				{
					if (j == 0)
						dp[i][j] = (dp[i - 1][j]);
					else
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + 1);
				}
			}
			else // j가 2번 나무에 있음
			{
				if (Plum[i] == 1) // 자두가 1번 나무에 있음
				{
					if (j == 0)
						dp[i][j] = dp[i - 1][j];
					else
						dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + 1);
				}
				else
					dp[i][j] = max(dp[i - 1][j] + 1, dp[i - 1][j - 1] + 1);
			}
		}
	}
	int res = 0;
	for (int i = 0; i <= w; i++)
	{
		res = max(res, dp[t][i]);
	}
	return res;
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	cout << solve();
}