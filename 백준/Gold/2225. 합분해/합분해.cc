#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;
#define MAX 202
#define MOD 1000000000
int n, k;
int dp[MAX][MAX];
void input() {
	cin >> n >> k;
	memset(dp, -1, sizeof(dp));
}

int re_dp(int cnt, int cur) {
	if (cnt == k) {
		if (cur == n) return 1;
		return 0;
	}
	if (dp[cnt][cur] != -1) return dp[cnt][cur];
	int t = 0;
	
	for (int nxt = 0; (nxt + cur) <= n; nxt++) {
		t += (re_dp(cnt + 1, cur + nxt));
		t %= MOD;
	}
	return dp[cnt][cur] = t;
}
int solve() {
	int res = re_dp(0, 0);
	return res;
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	cout << solve();
}