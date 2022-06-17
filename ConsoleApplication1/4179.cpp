#include <queue>
#include <iostream>
#include <string>
using namespace std;
#define X first
#define Y second
#define MAX 1005
#define wall -1
#define fire -1
#define able 0
#define jh 1
int R, C;
int board[MAX][MAX];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue <pair<int, int>> h;
queue <pair<int, int>> f;
void input()
{
	char c;
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> c;
			if (c == '#')
				board[i][j] = wall;
			else if (c == 'F')
			{
				board[i][j] = fire;
				f.push({ i,j });
			}
			else if (c == 'J')
			{
				board[i][j] = jh;
				h.push({ i,j });
			}
			else // c == '.'
				board[i][j] = able;

		}
	}

}
string solve()
{

	int dist = 0;
	while (!h.empty())
	{
		
		int size = h.size();
		while (size--)
		{
			pair <int, int> cur = h.front(); h.pop();
			if (board[cur.X][cur.Y] == wall) continue;
			if (cur.X == 0 || cur.Y == 0 || cur.X == R - 1 || cur.Y == C - 1) return to_string(board[cur.X][cur.Y]);
			for (int dir = 0; dir < 4; dir++)
			{
				int tx = cur.X + dx[dir];
				int ty = cur.Y + dy[dir];
				if (tx < 0 || tx >= R || ty < 0 || ty >= C) continue;
				if (!board[tx][ty])
				{
					board[tx][ty] = board[cur.X][cur.Y] + 1;
					h.push({ tx,ty });
				}
			}
		}
		size = f.size();
		while (size--)
		{
			pair <int, int> cur = f.front(); f.pop();
			for (int dir = 0; dir < 4; dir++)
			{
				int tx = cur.X + dx[dir];
				int ty = cur.Y + dy[dir];
				if (tx < 0 || tx >= R || ty < 0 || ty >= C) continue;
				if ((board[tx][ty] != -1) && (board[tx][ty] != 1))
				{
					board[tx][ty] = -1;
					f.push({ tx,ty });
				}
			}
		}
	}
	return "IMPOSSIBLE";
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	input();
	cout << solve();
}