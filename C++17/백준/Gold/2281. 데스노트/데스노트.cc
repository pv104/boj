#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1002
#define INF (int)2e9
int N, M;
int dp[MAX][MAX], arr[MAX];

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = 0; i < MAX; i++)
		fill(dp[i], dp[i] + MAX, INF);
}
// idx만큼 갔을때 cnt만큼 남은 최소값
int re_dp(int idx, int cnt) {

	if (idx == N)
		return 0;
	int sq = cnt * cnt;
	int& t = dp[idx][cnt];
	if (t != INF) return t;
		if (cnt - arr[idx] > 0)
			t = re_dp(idx + 1, cnt - 1 - arr[idx]);
			t = min(t,re_dp(idx + 1, M - arr[idx]) + sq);
	return t;
}
int solve() {
	int res = re_dp(0, 0);
	return res;
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	input(); cout << solve();
}