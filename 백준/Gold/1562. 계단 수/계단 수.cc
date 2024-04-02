#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;
#define MAX 102
#define INF 987654321
#define MOD 1000000000
int dp[MAX][10][1 << 10];
int n;
int re_dp(int idx, int cur, int visited) {
	// 종료
	if (idx == n) {

		if (visited == ((1 << 10) - 1)) {
			return 1;
		}
		return 0;
	}
	if (dp[idx][cur][visited] != -1) return dp[idx][cur][visited];
	dp[idx][cur][visited] = 0;

	int t = 0;
	if (cur == 0) {
		t += (re_dp(idx + 1, cur + 1, visited | 1 << (cur + 1)) % MOD);
		t %= MOD;
	}
	else if (cur == 9) {
		t += (re_dp(idx + 1, cur - 1, visited | 1 << (cur - 1)) % MOD);
		t %= MOD;
	}
	else {
		t += (re_dp(idx + 1, cur + 1, visited | 1 << (cur + 1)) % MOD);
		t %= MOD;
		t += (re_dp(idx + 1, cur - 1, visited | 1 << (cur - 1)) % MOD);
		t %= MOD;
	}
	t %= MOD;
	return dp[idx][cur][visited] = t;

}
void input() {
	cin >> n;
	memset(dp, -1, sizeof(dp));
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	int res = 0;
	for (int i = 1; i <= 9; i++) {

		res +=re_dp(1, i, 1 << i);
		res %= MOD;
	}
	cout << res;
	
}