#include <iostream>
using namespace std;
#define ll long long
#define MAX 1000003
#define MOD 1000000009
ll t, n;
ll dp[MAX];

int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> t;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		for (int i = 4; i <= n; i++)
			dp[i] = (dp[i - 1] % MOD + dp[i - 2] % MOD + dp[i - 3] % MOD) % MOD;
		cout << dp[n] << "\n";
	}
}