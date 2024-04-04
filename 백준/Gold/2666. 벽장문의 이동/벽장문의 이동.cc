#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
#define MAX 22
int N, w1, w2, M;
int arr[MAX], dp[MAX][MAX][MAX];
void input() {
	cin >> N >> w1 >> w2 >> M;
	for (int i = 0; i < M; i++)
		cin >> arr[i];
	memset(dp, -1, sizeof(dp));
}
int re_dp(int idx, int i,int j) {

	if (idx == M) 
		return 0;
	if (dp[idx][i][j] != -1) return dp[idx][i][j];

	int t = min(re_dp(idx + 1, arr[idx], j) + abs(i - arr[idx]),
		re_dp(idx + 1, i, arr[idx]) + abs(j - arr[idx]));
	return dp[idx][i][j] = t;
}
int solve() {
	int res = re_dp(0,w1,w2);
	return res;
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0); input(); cout << solve();
}