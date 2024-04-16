#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;
#define MAX 1000002
#define ll long long
#define MOD (ll)1e9
ll dp[MAX], N;

void input() {
	cin >> N;
}
ll solve() {
	dp[2] = 1;
	dp[3] = 2;
	for (int i = 4; i <= N; i++) {
		dp[i] = ((((dp[i - 2] + dp[i - 1]) % MOD) * (i - 1)) % MOD);
	}
	return dp[N];
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	input(); cout << solve();
}