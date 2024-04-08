#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <queue>
using namespace std;
#define MAX 102
#define BLACK -1
int board[MAX][MAX];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int type[5][4] = { {}, // 0
{-1,-1,1,0},
{1,-1,-1,2},
{3,2,-1,-1},
{-1,0,3,-1}
};
int N;
pair<int, int> worm[11][2];
void init() {
	for (int i = 0; i < MAX; i++) {
		fill(board[i], board[i] + MAX, 0);
	}
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 2; j++)
			worm[i][j].first = worm[i][j].second = -1;
}
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
			if (board[i][j] > 5) {
				if (worm[board[i][j]][0].first == -1)
				{
					worm[board[i][j]][0].first = i;
					worm[board[i][j]][0].second = j;
				}
				else
				{
					worm[board[i][j]][1].first = i;
					worm[board[i][j]][1].second = j;
				}
			}
		}
	}
}
int bfs(int R,int C,int DIR) {
	int r = R, c = C, dir = DIR;
	int block = 0, nr = r, nc = c, score = 0;
	while (true) {
		nr += dx[dir];
		nc += dy[dir];
		// 벽에 부딪힌 경우
		if (nr < 0 || nc < 0 || nr >= N || nc >= N || board[nr][nc] == 5) {
			return score * 2 + 1;
		}
		block = board[nr][nc];
		// 제자리로 돌아왔거나, 블랙홀에 빠진 경우
		if ((nr == R && nc == C)
			|| (block == BLACK)) {
			return score;
		}
		// 웜홀을 만난 경우 => 방향 유지
		if (block > 5) {
			auto curWorm = worm[block][0];
			if (nr == curWorm.first && nc == curWorm.second) {
				curWorm = worm[block][1];
			}
			nr = curWorm.first;
			nc = curWorm.second;
		}
		// 블럭인 경우
		else if (block > 0) {
			dir = type[block][dir];
			if (dir == -1) return score * 2 + 1;
			score++;
		}
	}
}
int solve() {
	int res = 0;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++)
		{
			if (board[r][c] != 0) continue;
			for (int dir = 0; dir < 4; dir++)
			{
				res = max(res, bfs(r,c,dir));
			}
		}
	}
	return res;
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int T;
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		init();
		input();
		cout << "#" << TC << " " << solve() << "\n";
	}

}