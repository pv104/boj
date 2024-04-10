#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
#define MAX 10
#define pii pair <int,int>
#define Y first
#define X second
int N, K, maxValue, res, startSize;
int board[MAX][MAX];
bool visited[MAX][MAX];
pii start[5];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
void init() {
	memset(board, 0, sizeof(board));
	memset(start, -1, sizeof(start));
	maxValue = 0;
	res = 0;
	startSize = 0;
}
void input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
			maxValue = max(board[i][j], maxValue);
		}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == maxValue) {
				start[cnt].Y = i;
				start[cnt++].X = j;
			}
		}
	}
	startSize = cnt;
}
void re_dp(int r, int c, int cur, int isDrill,int cnt,int k) {
	//cout << " r: " << r << " c: " << c << " cur: " << cur << " tf: " << isDrill
		//<< " cnt: " << cnt << "\n";
	for (int dir = 0; dir < 4; dir++) {
		int nr = r + dy[dir];
		int nc = c + dx[dir];
		if (nr < 0 || nc < 0 || nr >= N || nc >= N || visited[nr][nc]) continue;
		int nxt = board[nr][nc];
		if (nxt < cur) {
			visited[nr][nc] = true;
			re_dp(nr, nc, board[nr][nc], isDrill, cnt + 1, k);
			visited[nr][nc] = false;
		}
		else if (isDrill == 0 && (nxt - k) < cur) {
			visited[nr][nc] = true;
			re_dp(nr, nc, nxt - k, 1, cnt + 1, k);
			visited[nr][nc] = false;
		}
	}
	res = max(res, cnt);
	return;
}
int solve() {
	for (int i = 0; i < startSize; i++)
	{
		for (int k = 1; k <= K; k++) 
		{
			auto cur = start[i];
			memset(visited, false, sizeof(visited));
			int r = cur.Y;
			int c = cur.X;
			int val = board[r][c];
			visited[r][c] = true;
			re_dp(r, c, val, 0, 1, k);
			visited[r][c] = false;
		}
	}
	return res;
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	//FILE* stream;
	//freopen_s(&stream, "input.txt", "r", stdin);
	//freopen_s(&stream, "output.txt", "w", stdout);
	int T;
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		init();
		input();
		cout << "#" << TC << " " << solve() << "\n";
	}
}