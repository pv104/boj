#include <iostream>
using namespace std;
#define MAX 502
int val[MAX][MAX]; // 1 1부터 채우고, 0은 빈칸으로 쓰기
int dp[MAX][MAX]; // dp[i][j] = 현재값을 포함해서 얻은 최대값
int n;
void input()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			cin >> val[i][j];
}
int solve()
{
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + val[i][j];
		}
	}
	
	for (int i = 1; i <= n; i++)
		res = max(dp[n][i], res);
	return res;

}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	cout << solve();
}