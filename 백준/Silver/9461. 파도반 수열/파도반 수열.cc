#include <iostream>
using namespace std;
long long dp[101] = { -1, 1,1,1,2,2,3,4,5,7,9 };
long long solve(long long n)
{
	if (dp[n] != -1)
		return dp[n];
	else
	{
		dp[n] = (solve(n - 1) + solve(n - 5));
		return dp[n];
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 10; i < 101; i++)
		dp[i] = -1;
	long long n, t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		cout << solve(n) << endl;
	}
	
}