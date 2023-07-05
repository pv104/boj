#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1002
int val[MAX], dp[MAX];
int n;
void input()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> val[i];
}
int solve()
{
	dp[1] = 1;
	int lis = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (val[j] < val[i])
				dp[i] = max(dp[j] + 1, dp[i]);
			
		}
		if (dp[i] == 0) 
			dp[i] = 1;
	}
	for (int i = 1; i <= n; i++)
		lis = max(lis, dp[i]);
	return lis;

}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	cout << solve();
}