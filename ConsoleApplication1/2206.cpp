#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
#define X first
#define Y second
#define MAX 1002
int board[MAX][MAX];
int dist[MAX][MAX][2]; // [0] = 벽을 안 부순 최단거리, [1] = 벽을 부순 최단거리
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;
void input()
{
	cin >> n >> m;
	char c;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> c;
			board[i][j] = (c - '0');
		}
	}
}
int solve()
{

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			dist[i][j][0] = dist[i][j][1] = -1;
			dist[0][0][0] = dist[0][0][1] = 1;
			queue <tuple<int, int, int>> q;
			q.push({ 0,0,0 });
			
			while (!q.empty())
			{
				int x, y, broken;
				tie(x, y, broken) = q.front(); q.pop();
				if (x == n - 1 && y == m - 1) return dist[x][y][broken];
				int nextdist = dist[x][y][broken] + 1;
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (board[nx][ny] == 0 && dist[nx][ny][broken] == -1) // 벽이 아니고, 아직 가지 않은 정점
					{
						dist[nx][ny][broken] = nextdist;
						q.push({ nx,ny,broken });
					}
					if (!broken && board[nx][ny] == 1 && dist[nx][ny][1] == -1) // 아직 벽을 부순적 없고, 벽이고,
																		// 아직 가지 않은 정점
					{
						dist[nx][ny][1] = nextdist;
						q.push({ nx,ny,1 });
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