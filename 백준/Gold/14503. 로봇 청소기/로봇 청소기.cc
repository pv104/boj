#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define X first.first
#define Y first.second
#define DIR second
#define MAX 52
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int board[MAX][MAX], n, m, r, c, d;
queue <pair<pair<int, int>, int>> q;
bool BFS(int x, int y, int dir)
{
	x += dx[dir];
	y += dy[dir];
	if (board[x][y] == 0)
	{
		q.push({ {x,y},dir });
		return true;
	}
	else return false;
}
int solve()
{
	int res = 0;
	while (true)
	{
		auto cur = q.front(); q.pop();
		int x = cur.X;
		int y = cur.Y;
		int dir = cur.DIR;
		bool flag = false;
		if (board[x][y] == 0)
			board[x][y] = -1;
		for (int i = 0; i < 4; i++)
		{
			if (dir == 0)
				dir = 3;
			else
				dir--;
			flag = BFS(x, y, dir);
			if (flag == true) break;


		}
		if (flag == true)
			continue;
		if (dir == 0)
		{
			x += dx[2], y += dy[2];
		}
		else if (dir == 1)
		{
			x += dx[3], y += dy[3];
		}
		else if (dir == 2)
		{
			x += dx[0], y += dy[0];
		}
		else
		{
			x += dx[1], y += dy[1];
		}

		if (board[x][y] == 1)
			break;
		else
			q.push({ {x,y},dir });
	}
	for (int i=0; i<n; i++)
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == -1) res++;
		}
	return res;

}
void input()
{
	cin >> n >> m >> r >> c >> d;
	q.push({ {r,c},d });
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	cout << solve();
}