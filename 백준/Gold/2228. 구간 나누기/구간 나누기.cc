#include <algorithm>
#include <iostream>
#include <memory.h>
using namespace std;
#define MAX 102
#define INF -987654321
int N, M;
int arr[MAX], dp[MAX][MAX][2];
void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			for (int k = 0; k < 2; k++)
				dp[i][j][k] = INF;
}
int re_dp(int idx, int m, int isUsed) {

	if (m > M) return INF;
	if (idx == N) {
		if (m == M)
			return 0;
		return INF - 1;
	}
	if (dp[idx][m][isUsed] != INF) return dp[idx][m][isUsed];

	int t = re_dp(idx + 1, m, 0); // 현재 구간을 그대로 가져가는 경우
	if (isUsed == 0) {// 안씀 
		t = max(t, re_dp(idx + 1, m + 1, 1) + arr[idx]); // 다음 구간을 만들면서 해당 구간의 첫 원소로 지금 인덱스를 사용
	}
	else {// 씀
		t = max(t, re_dp(idx + 1, m, 1) + arr[idx]); // 현재 구간을 버리고 새로운 구간을 만드는 경우
	}


	return dp[idx][m][isUsed] = t;
}
int solve() {

	int res = re_dp(0, 0, 0);

	return res;
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0); input(); cout << solve();
}