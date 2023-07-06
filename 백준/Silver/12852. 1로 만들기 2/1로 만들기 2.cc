#include <iostream>
#include <vector>
using namespace std;
#define MAX 1000003
#define INF 987654321
int dp[MAX][3]; //dp[0] = -1, dp[1] = /2, dp[2] = /3
int n;
void input()
{
	cin >> n;
	for (int i = 2; i <= n; i++)
		for (int j = 0; j < 3; j++)
			dp[i][j] = INF;
}
void solve(int& res, vector <int>& numbers)
{
	
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			dp[i][0] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + 1;
			if (i % 2 == 0)
				dp[i][1] = min(dp[i / 2][0], min(dp[i / 2][1], dp[i / 2][2])) + 1;
			else dp[i][1] = INF;
			if (i % 3 == 0)
				dp[i][2] = min(dp[i / 3][0], min(dp[i / 3][1], dp[i / 3][2])) + 1;
			else dp[i][2] = INF;
		}
	}
	res = min(dp[n][0], min(dp[n][1], dp[n][2]));
	if (res == INF) res = 0;
	int findNum = res;
	for (int i = n; i > 0; )
	{
		if (findNum == 0) break;
		for (int j = 0; j < 3; j++)
		{
			if (findNum == dp[i][j])
			{
				findNum--;
				numbers.push_back(i);
				if (j == 0)
					i--;
				else if (j == 1)
					i /= 2;
				else
					i /= 3;
				break;
			}
		}
	}
	numbers.push_back(1);
	return;
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	vector <int> numbers;
	int res = 0;
	input();
	solve(res, numbers);
	cout << res << "\n";
	for (auto i : numbers)
		cout << i << ' ';
}