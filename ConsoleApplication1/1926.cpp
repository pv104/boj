#include <iostream>
#include <queue>
#include <algorithm>
#define X first
#define Y second
#define MAX 502
using namespace std;
queue <pair<int,int>> Q;
int board[MAX][MAX];
bool vis[MAX][MAX];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m, drawing, maxLength;
void input()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	}
}
pair <int, int> solve()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (vis[i][j] == false && board[i][j] == 1)
			{
				drawing++;
				vis[i][j] = true;
				Q.push({ i,j });
				int cnt = 0;
				while (!Q.empty())
				{
					cnt++;
					pair<int, int> cur = Q.front(); Q.pop();
					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (vis[nx][ny] == true || board[nx][ny] == 0) continue;
						
						vis[nx][ny] = true;
						Q.push({ nx,ny });
					}
				}
				maxLength = max(maxLength, cnt);
			}
		}
	}

	return { drawing,maxLength };
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	input();
	cout << solve().X << "\n" << solve().Y;
}