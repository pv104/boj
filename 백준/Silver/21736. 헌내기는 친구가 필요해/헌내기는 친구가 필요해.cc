#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 603
char board[MAX][MAX];
bool visited[MAX][MAX];
int n, m;
#define SPACE 'O'
#define WALL 'X'
#define PEOPLE 'P'
#define DOYEON 'I'
#define X first
#define Y second
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue <pair<int, int>> q;
void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if(board[i][j] == DOYEON) {
				q.push({ i,j });
				visited[i][j] = true;
			}
		}
	}
	
}
int solve() {
	int res = 0;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = dx[dir] + cur.X;
			int ny = dy[dir] + cur.Y;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) continue;
			if (board[nx][ny] == WALL) continue;
			visited[nx][ny] = true;
			q.push({ nx,ny });
			if (board[nx][ny] == PEOPLE) res++;
		}
	}
	return res;
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	int res = solve();
	if (res == 0) cout << "TT";
	else cout << res;
}