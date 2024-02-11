#include <iostream>
#include <vector>
#include <queue>
#define MAX 8
using namespace std;
constexpr int SPACE = 0;
constexpr int WALL = 1;
constexpr int VIRUS = 2;
int n, m;
queue <pair<int, int>> q;
vector <pair<int, int>> start;
int board[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == VIRUS) start.push_back({ i,j });
		}
	}
}
int bfs(vector<pair<int,int>>& WALLS) {
	
	vector<vector<int>> tboard(n);
	for (int i = 0; i < n; i++)
		tboard[i].resize(m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			tboard[i][j] = board[i][j];

	for (auto i : WALLS) {
		tboard[i.first][i.second] = WALL;
	}

	for (auto i : start) {
		visited[i.first][i.second] = true;
		q.push(i);
	}
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = dx[dir] + cur.first;
			int ny = dy[dir] + cur.second;
			if (nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny] || tboard[nx][ny] != SPACE) continue;
			q.push({ nx,ny });
			visited[nx][ny] = true;
			tboard[nx][ny] = VIRUS;
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = false;
			if (tboard[i][j] == SPACE) res++;
		}
	}
	return res;
}
int solve() {
	int res = 0;
	for (int i = 0; i < n * m; i++) {
		vector<pair<int, int>> walls;
		
		if (board[i / m][i % m] != SPACE) continue;
		
		for (int j = i + 1; j < n * m; j++) {
			if (i == j) continue;
			if (board[j / m][j % m] != SPACE) continue;
			
			for (int k = j + 1; k < n * m; k++) {
				if (i == k || j == k) continue;
				if (board[k / m][k % m] != SPACE) continue;
				walls.push_back({ i / m, i % m });
				walls.push_back({ j / m, j % m });
				walls.push_back({ k / m, k % m });
				res = max(res, bfs(walls));
				walls.clear();
			}
		}
	}
	return res;
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	cout << solve();
}