#include <iostream>
#include <queue>
using namespace std;
#define X first
#define Y second
#define MAX 1005
int board[MAX][MAX];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int m, n;
queue <pair<int, int>> q;
void input()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];

			if (board[i][j] == 1) q.push({ i,j });
		}
	}
}
int solve()
{
	int day = 0;
	pair <int, int> cur;

	while (!q.empty())
	{
		cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int tx = cur.X + dx[dir];
			int ty = cur.Y + dy[dir];
			if (tx < 0 || tx >= m || ty < 0 || ty >= n) continue;

			if (!board[tx][ty])
			{
				board[tx][ty] = (board[cur.X][cur.Y] + 1);
				q.push({ tx,ty });
			}
		}
	}
	
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			day = max(day, board[i][j]);
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!board[i][j])
				return -1;
		}
	}
	return day - 1;
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	cout << solve();
}