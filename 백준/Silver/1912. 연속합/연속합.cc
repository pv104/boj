#include <iostream>
using namespace std;
#define MAX 100002
int n;
int val[MAX], dp[MAX][2];// [0] = 더한 값, [1] = 해당 값, <0 = 0
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
		dp[i][0] = dp[i - 1][0] + val[i];
		if (dp[i][0] < 0)
			dp[i][0] = 0;
		dp[i][1] = val[i];
		if (dp[i][1] < 0)
			dp[i][1] = val[i];
	}
	int mRes = -1002;
	for (int i = 1; i <= n; i++)
	{
		mRes = max(mRes, val[i]);
		for (int j = 0; j < 2; j++)
			res = max(res, dp[i][0]);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 2; j++)
			if (dp[i][0] != 0)
				return res;
	}
	return mRes;

}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	cout << solve();
}