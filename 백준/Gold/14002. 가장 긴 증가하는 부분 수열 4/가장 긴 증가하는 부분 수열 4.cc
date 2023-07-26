#include <iostream>
#include <stack>
using namespace std;
#define MAX 1002
#define LEN first
#define IDX second
int A[MAX];
pair <int, int> dp[MAX];
int n;
stack <int> S;
void input()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> A[i];
}
int solve()
{
	dp[1].LEN = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (A[j] < A[i])
			{
				if (dp[i].LEN < dp[j].LEN + 1)
				{
					dp[i].LEN = dp[j].LEN + 1;
					dp[i].IDX = j;
				}
			}
		}
		if (dp[i].LEN == 0)
		{
			dp[i].LEN = 1;
			dp[i].IDX = i;
		}
	}int res = 0, idx = 0;
	for (int i = 1; i <= n; i++)
	{
		if (res < dp[i].LEN)
		{
			res = dp[i].LEN;
			idx = i;
		}
	}
	while (res != S.size())
	{
		S.push(idx);
		idx = dp[idx].IDX;
	}
	return res;
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	cout << solve() << "\n";
	while (!S.empty())
	{
		cout << A[S.top()] << " ";
		S.pop();
	}

}