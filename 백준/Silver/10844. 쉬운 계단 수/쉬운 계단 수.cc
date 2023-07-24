#include <iostream>
using namespace std;
#define MAX 102
#define MOD 1000000000
int dp[MAX][10];

int n;
int findStairNum(int k, int cur)
{
	if (k == 0) return 0;
	if (k == 1 && cur == 0) return 1;
	if (dp[k][cur] != 0) return dp[k][cur];

	if (cur == 0)
	{
		dp[k][cur] = findStairNum(k - 1, cur + 1);
		if (dp[k][cur] > MOD) dp[k][cur] %= MOD;
	}
	else if (cur == 9)
	{
		dp[k][cur] = findStairNum(k - 1, cur - 1);
		if (dp[k][cur] > MOD) dp[k][cur] %= MOD;
	}
	else
	{
		dp[k][cur] = findStairNum(k - 1, cur - 1) + findStairNum(k - 1, cur + 1);
		if (dp[k][cur] > MOD) dp[k][cur] %= MOD;
	}
	
	return dp[k][cur];
}
int main()
{
	int x = 1;
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= 9; i++)
		dp[1][i] = 1;
	int sum = 0;
	for (int i = 1; i <= 9; i++)
	{
		sum += findStairNum(n,i);
		sum %= MOD;
	}

	cout << sum;
}