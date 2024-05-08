#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
#define SIZE 33
#define ll long long
#define INF (ll)3e9
ll N, L, I;
ll dp[SIZE][SIZE];

void input() {
	cin >> N >> L >> I;
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= i; j++) {
			if (i == 0 || j == 0)
			{
				dp[i][j] = 1;
				continue;
			}
			
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];

		}
	}

	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++) {
			if (i == 0 || j == 0)
			{
				dp[i][j] = 1;
				continue;
			}
			dp[i][j] = dp[i][j - 1] + dp[i][j];

		}
	}


}
// 현재 위치 i, dp[n-1][j] < i => 1, 
void rec(ll n, ll l, ll i) {

	if (n == 0) return;
	/*cout << " n : " << n << " l : " << l << " i : " << i << "\n";*/
	if (dp[n-1][l-1] < i && dp[n-1][l] < i)
	{
		cout << 1;
		rec(n - 1, l - 1, i - (dp[n-1][l]));
	} 
	else
	{
		cout << 0;
		rec(n - 1, l, i);
	}
	return;
}
void solve() {
	rec(N, L, I);
}
int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	input(); solve();
}