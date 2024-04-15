#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
#define MAX 102
#define NMAX 22
int T, N, res;
int board[NMAX][NMAX];
bool visited[NMAX][NMAX], desserts[MAX], dirs[4];
int dy[4] = { -1,1,1,-1 };
int dx[4] = { 1,1,-1,-1 };
void init() {
	memset(board, 0, sizeof(board));
	memset(visited, false, sizeof(visited));
	memset(desserts, false, sizeof(desserts));
	res = -1;
}
bool OOB(int r, int c) {
	return r < 0 || c < 0 || r >= N || c >= N;
}
void input() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
		}

	}
}
void dfs(int R,int C, int r, int c, int d, int cnt)
{

	for (int dd = 0; dd < 4; dd++) {
		int dir = (d + dd) % 4;
		int nr = r + dy[dir];
		int nc = c + dx[dir];
		if (OOB(nr,nc) || dirs[dir]) continue;
		if (visited[nr][nc]) {
			if (cnt > 3 && nr == R && nc == C) {
				res = max(res, cnt);
				return;
			}
			continue;
		}
		int dessert = board[nr][nc];
		if (desserts[dessert]) continue;
		visited[nr][nc] = desserts[dessert] = true;
		if (d != dir) {
			// 방향이 달라지면
			dirs[d] = true;
		}
		dfs(R, C, nr, nc, dir, cnt + 1);
		visited[nr][nc] = desserts[dessert] = false;
		dirs[d] = false;
	}
	return;
}
int solve() {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == 0 && j == 0 || i == N - 1 && j == 0 || i == 0 && j == N - 1 || i == N - 1 && j == N - 1) continue;
			visited[i][j] = desserts[board[i][j]] = true;
			dfs(i, j, i, j, 0, 1);	
			memset(dirs, false, sizeof(dirs));
			visited[i][j] = desserts[board[i][j]] = false;
		}
	}
	return res;
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	//FILE* stream;
	//freopen_s(&stream, "input.txt", "r", stdin);
	//freopen_s(&stream, "output.txt", "w", stdout);
	cin >> T;

	for (int TC = 1; TC <= T; TC++)
	{
		init();
		input();
		cout << "#" << TC << " " << solve() << "\n";
	}
}