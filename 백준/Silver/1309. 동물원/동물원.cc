#include <iostream>
#include <algorithm>
using namespace std;
int n;
#define MOD 9901
#define MAX 100002
int dp[MAX]; // 사자를 놓는 경우의 수
int solve() {
	dp[0] = 1; // 사자 0마리 놓음
	int res = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		dp[i] = (dp[i - 2] % MOD + (dp[i - 1] << 1) % MOD) % MOD;
	}

	return (dp[n - 1] + dp[n]) %MOD;

}
int main() {
	cin.tie(0); ios::sync_with_stdio(0); cout << solve();
}