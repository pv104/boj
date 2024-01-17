#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 255
#define X first
#define Y second
int r, c, w, s;
bool visited[MAX][MAX];
char board[MAX][MAX];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue <pair<int, int>> q;
vector <pair<pair<int, int>, char>> v;
void input() {
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
		}
}
void solve() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			int tw = 0, ts = 0;
			if (!visited[i][j] && (board[i][j] == 'k') || (board[i][j] == 'v'))
			{
				q.push({ i,j });
				visited[i][j] = true;
				v.push_back({ {i,j},board[i][j] });
				if (board[i][j] == 'k')
					ts++;
				else tw++;
				while (!q.empty()) {
					auto cur = q.front(); q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = dx[dir] + cur.X;
						int ny = dy[dir] + cur.Y;
						if (nx < 0 || ny < 0 || nx >= r || ny >= c || visited[nx][ny] || board[nx][ny] == '#') continue;
						if (board[nx][ny] == 'k') {
							ts++;
							v.push_back({{nx,ny},board[nx][ny]});
						}
						if (board[nx][ny] == 'v') {
							tw++;
							v.push_back({{nx,ny},board[nx][ny]});
						}	
						q.push({ nx,ny });
						visited[nx][ny] = true;
					}
				}
				if (ts > tw) { // 양
					for (auto i : v) {
						if(i.Y == 'v')
						board[i.X.X][i.X.Y] = '.';
					}
				}
				else {
					for (auto i : v) {
						if(i.Y == 'k')
						board[i.X.X][i.X.Y] = '.';
					}
				}
				v.clear();
			}
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board[i][j] == 'k') s++;
			if (board[i][j] == 'v') w++;
		}
	}
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	solve();
	cout << s << ' ' << w;
	return 0;
}