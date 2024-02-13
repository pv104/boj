#include <iostream>
using namespace std;
constexpr int MAX = 5006;
constexpr int INF = 987654321;
int dp[MAX];
int n;
int f(int c) {
	if (c < 3 || c == 4 || c == 7) return INF;
	if (c == 3 || c == 5) return 1;
	if (dp[c] != INF) return dp[c];
	return dp[c] = min(f(c - 3) + 1, f(c - 5) + 1);
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n;
	fill(dp, dp + MAX, INF);
	dp[n] = f(n);
	if (dp[n] == INF) dp[n] = -1;
	cout << dp[n];
}