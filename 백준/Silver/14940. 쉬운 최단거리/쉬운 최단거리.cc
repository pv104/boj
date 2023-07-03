#include <iostream>
#include <queue>
using namespace std;
#define MAX 1002
#define X first
#define Y second
int board[MAX][MAX];
bool visited[MAX][MAX];
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue <pair<pair<int, int>, int>> q;
void input()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 2)
			{
				q.push({ {i,j},0 });
				visited[i][j] = true;
				board[i][j] = 0;
			}
		}
	}
}
void solve()
{
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = dx[dir] + cur.X.X;
			int ny = dy[dir] + cur.X.Y;
			int nxt = cur.Y + 1;
			if (nx < 0 || ny < 0 || nx > n || ny > m || visited[nx][ny] || !board[nx][ny]) continue;
			q.push({ {nx,ny},nxt });
			board[nx][ny] = nxt;
			visited[nx][ny] = true;
		}
	}
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0);
	cin >> n >> m;
	input();
	solve();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 1 && !visited[i][j]) cout << -1 << ' ';
			else cout << board[i][j] << ' ';
		}
		cout << "\n";
	}
}