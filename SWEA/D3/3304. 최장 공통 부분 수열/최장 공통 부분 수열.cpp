#include <iostream>
using namespace std;
#define MAX 1002
int dp[MAX][MAX];
string s1, s2;
int r, c;
void init()
{
	for (int i = 0; i < MAX; i++)
		fill(dp[i], dp[i] + MAX, 0);
	cin >> s1 >> s2;
	r = s2.length();
	c = s1.length();
	return;
}
int solve()
{
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (s2[i-1] == s1[j-1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
			
				dp[i][j] = max(dp[i-1][j],dp[i][j - 1]);
			}
		}
	}
	return dp[r][c];
}
int main()
{
	
	cin.tie(0); ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		init();
		cout << '#' << i << ' ' << solve() << "\n";
	}
	return 0;
}
