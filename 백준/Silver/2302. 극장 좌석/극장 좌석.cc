#include <iostream>
using namespace std;
#define MAX 42
int dp[MAX];
int fix[MAX];
int n, m;
void input()
{
	cin >> n >> m;
	int t;
	for (int i = 0; i < m; i++)
	{
		cin >> t;
		fix[t] = 1;
	}
}
int solve()
{
	
		int n1 = 0, n2 = 1;
		int tt = 0;
		for (int i = 1; i < MAX; i++)
		{
			tt = n1 + n2;
			n1 = n2;
			n2 = tt;
			dp[i] = tt;
		}
	
	int res = 1;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (fix[i] == 1)
		{
			if(cnt != 0)
			res *= dp[cnt];
			cnt = 0;
		}
		else
		{
			cnt++;
		}
	}
	
	if (cnt != 0)
		res *= dp[cnt];

	return res;
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	cout << solve();
}