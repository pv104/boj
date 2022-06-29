#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 202
#define MMAX 32
#define X first
#define Y second
int board[MAX][MAX];
int dist[MAX][MAX][MMAX];
bool vis[MAX][MAX][MMAX];
int k, w, h;
int hdx[8] = { 2,1,-1,-2,-2,-1,1,2 };
int hdy[8] = { 1,2,2,1,-1,-2,-2,-1 };
int mdx[4] = { 1,0,-1,0 };
int mdy[4] = { 0,1,0,-1 };
queue <tuple <int, int, int>> q;
bool OOB(int x, int y)
{
	if (x < 0 || y < 0 || x >= w || y >= h) return true;
	return false;
}
void input()
{
	cin >> k >> h >> w;
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
			cin >> board[i][j];
	}
}
int solve()
{
	if (w == 1 && h == 1) return 0;
	q.push({ 0,0,0 });
	vis[0][0][0] = true;
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		int x, y, horse;
		tie(x, y, horse) = cur;
		if (x == w - 1 && y == h - 1)
		{
			return dist[x][y][horse];
		}

		if (horse < k)
		{
			for (int dir = 0; dir < 8; dir++)
			{
				int nx = x + hdx[dir];
				int ny = y + hdy[dir];
				if (OOB(nx, ny) || board[nx][ny] == 1) continue;

					if (!vis[nx][ny][horse+1]) // (x,y,i+1)에 값이 없으면
					{
						dist[nx][ny][horse + 1] = dist[x][y][horse] + 1; // 말 1턴 쓰고 1칸 전진
						q.push({ nx,ny,horse + 1 });
						vis[nx][ny][horse + 1] = true;
					}
				
			}
		}

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = x + mdx[dir];
			int ny = y + mdy[dir];
			if (OOB(nx, ny) || board[nx][ny] == 1) continue;
			
				
				if (!vis[nx][ny][horse]) // (x,y)에 값이 없으면
				{
					dist[nx][ny][horse] = dist[x][y][horse] + 1; // 1칸 전진
					q.push({ nx,ny,horse });
					vis[nx][ny][horse] = true;
				}
			
		}
	}
	return -1;
}
int main()
{
	cin.tie(); ios::sync_with_stdio(0);
	input(); cout << solve();
}