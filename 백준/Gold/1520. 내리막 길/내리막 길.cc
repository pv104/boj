#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;
#define MAX 502
#define X first
#define Y second
int m, n;
int board[MAX][MAX];
int dp[MAX][MAX];
int start, last;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
queue <pair <int, int>> q;
void input() {
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	--m; --n;
	start = board[0][0];
	last = board[m][n];
	memset(dp, -1, sizeof(dp));
}
int r(pair <int, int> cur) {
	if (cur.X == m && cur.Y == n) {

		return 1;
	}
	if (dp[cur.X][cur.Y] != -1) return dp[cur.X][cur.Y];
	int t = 0;
	for (int dir = 0; dir < 4; dir++) {
		int nx = cur.X + dx[dir];
		int ny = cur.Y + dy[dir];

		if (nx < 0 || ny < 0 || nx > m || ny > n) continue;
		if (board[nx][ny] >= start || board[nx][ny] < last) continue;
		if (board[cur.X][cur.Y] <= board[nx][ny]) continue;
		t += r({ nx,ny });

		dp[cur.X][cur.Y] = t;

	}
	return max(dp[cur.X][cur.Y],0);
}
int solve() {
	int res = r({ 0,0 });

	return res;
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	cout << solve();
}