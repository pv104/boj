#include <algorithm>
#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;
#define MAX 302
#define INF 987654321
int N, M, K;
int arr[MAX][MAX];
int dp[MAX][MAX];
void input() {
	int a, b, c;
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		cin >> a >> b >> c;
		if (a > b) continue;
		if (arr[a][b] > c) continue;
		arr[a][b] = c;
	}
	memset(dp, -1, sizeof(dp));
}
int re_dp(int cur, int cnt) {

	if (cur == N) return 0;
	if (cnt >= M) return -INF;
	if (dp[cur][cnt] != -1) return dp[cur][cnt];
	dp[cur][cnt] = 0;
	for (int nxt = cur+1; nxt <= N; nxt++) {
		if (arr[cur][nxt] == 0) continue;
		dp[cur][cnt] = max(dp[cur][cnt],re_dp(nxt, cnt + 1) + arr[cur][nxt]);
	}
	if (dp[cur][cnt] == 0) dp[cur][cnt] = -INF;
	return dp[cur][cnt];
}
int solve() {
	re_dp(1, 1);
	int res = -1;
		for (int j = 0; j <= N; j++) {
			res = max(dp[1][j],res);
		}
	return res;
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	input(); cout << solve();
}