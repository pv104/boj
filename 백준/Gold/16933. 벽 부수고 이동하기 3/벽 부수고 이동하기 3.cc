#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 1002
#define KMAX 12
int board[MAX][MAX];
int dist[MAX][MAX][KMAX][2];
queue <tuple<int, int, int, int>> q;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m, k;
void input()
{
	cin >> n >> m >> k;
	char c;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> c;
			board[i][j] = c - '0';
		}
	}
}
int solve()
{
	q.push({ 0,0,0,true });
	dist[0][0][0][true] = 1;
	while (!q.empty())
	{
		int x, y, broken;
		bool day;
		tie(x, y, broken, day) = q.front(); q.pop();
		if (x == n - 1 && y == m - 1) return dist[x][y][broken][day];

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (broken < k)
			{
				if (board[nx][ny] && day && !dist[nx][ny][broken+1][!day])
				{
					dist[nx][ny][broken + 1][!day] = dist[x][y][broken][day] + 1;
					q.push({ nx,ny,broken + 1,!day });
				}
				
			}
			if (board[nx][ny] && !day && !dist[nx][ny][broken][!day])
			{
				dist[x][y][broken][!day] = dist[x][y][broken][day] + 1;
				q.push({ x,y,broken,!day });
			}
			if (!board[nx][ny] && !dist[nx][ny][broken][!day])
			{
				dist[nx][ny][broken][!day] = dist[x][y][broken][day] + 1;
				q.push({ nx,ny,broken,!day });
			}
		}
	}
	return -1;
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	cout << solve();
}