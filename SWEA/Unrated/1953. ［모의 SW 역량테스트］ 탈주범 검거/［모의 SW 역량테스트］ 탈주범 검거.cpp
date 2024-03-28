#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
int N, M, R, C, L;
#define MAX 52
#define X first
#define Y second
int board[MAX][MAX];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
bool visited[MAX][MAX];
map <int, vector<int>> dirs = 
{
	{0,{0}},
	{1,{0,1,2,3}},
	{2,{0,2}},
	{3,{1,3}},
	{4,{0,1}},
	{5,{1,2}},
	{6,{2,3}},
	{7,{0,3}}
};
map <int, vector<int>> tunnel =
{
	{0,{1,2,5,6}},
	{1,{1,3,6,7}},
	{2,{1,2,4,7}},
	{3,{1,3,4,5}}
};
void init() {
	memset(board, 0, sizeof(board));
	memset(visited, false, sizeof(visited));
}
void input() {
	cin >> N >> M >> R >> C >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
}
int solve() {

	int res = 0;
	int size = 0;
	queue<pair<int, int>> q;
	q.push({ R,C });
	visited[R][C] = true;
	int timer = 1;
	while (timer++ != L) {
		size = q.size();
		while (size-- != 0) {
			auto cur = q.front(); q.pop();
			int r = cur.X;
			int c = cur.Y;
			int curTunnel = board[r][c];
			auto idx = dirs.find(curTunnel);
			for (auto dir : idx->second) {
				int nr = r + dx[dir];
				int nc = c + dy[dir];
				if (nr < 0 || nc < 0 || nr >= N || nc >= M || visited[nr][nc] || board[nr][nc] == 0) continue;
				auto tunnelVector = tunnel.find(dir)->second;

				if (find(tunnelVector.begin(), tunnelVector.end(), board[nr][nc]) != tunnelVector.end()) {
					q.push({ nr,nc });
					visited[nr][nc] = true;
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j]) res++;
		}
	}
	return res;
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		init();
		input();
		cout << "#" << i << " " << solve() << "\n";
	}

}