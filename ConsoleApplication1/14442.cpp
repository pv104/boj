#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 1002
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int board[MAX][MAX];
int dist[MAX][MAX][11]; // [0] = 벽을 부수지 않은 최단거리, [1~k] = 벽을 i개 부순 최단거리
int n, m, k;
queue <tuple<int, int, int>> q;
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
	q.push({ 0,0,0 });
	dist[0][0][0] = 1; // 초기 설정
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		int x, y, broken;
		tie(x, y, broken) = cur;
		if (x == n - 1 && y == m - 1) return dist[x][y][broken];

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (broken < k)
			{
				if (board[nx][ny] == 1 && dist[nx][ny][broken + 1] == 0) // 벽이 있고,부술 수 있음
				{
					dist[nx][ny][broken+1] = dist[x][y][broken] + 1;
					q.push({ nx,ny,broken + 1 });
				}
			}
			if (board[nx][ny] == 0 && dist[nx][ny][broken] == 0) // 벽은 없지만 갈 수 있는 길
			{
				dist[nx][ny][broken] = dist[x][y][broken] + 1;
				q.push({ nx,ny,broken });
			}
		}
	}
	return -1;
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	input(); cout << solve();
}