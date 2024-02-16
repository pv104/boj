#include <iostream>
#include <queue>
#include <stack>
using namespace std;
#define X first
#define Y second
typedef struct sc {
	int x;
	int y;
	int alpha;
	int res;
}sc;
queue <sc> q;
stack <sc> s;
const int MAX = 22;
int r, c;
char board[MAX][MAX];
int visited[26 + 1];
int result;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
void input() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
		}
	}
	visited[board[0][0] - 'A'] = true;
}
int dfs(sc cur) {
	int x = cur.x;
	int y = cur.y;
	int alpha = cur.alpha;
	int res = cur.res;
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || ny < 0 || nx >= r || ny >= c || visited[board[nx][ny] - 'A']) continue;
		int nalpha = board[nx][ny] - 'A';
		visited[nalpha] = true;
		result = max(dfs({ nx,ny,nalpha,res+1 }),result);
		visited[nalpha] = false;
	}
	return res;
}
int solve() {
	result = max(result, dfs({ 0,0,board[0][0] - 'A', 1 }));
	return result;
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	cout << solve();
}