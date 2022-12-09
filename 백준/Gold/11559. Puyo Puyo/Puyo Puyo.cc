#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define R 12
#define C 6
#define X first
#define Y second
char board[R][C];
bool visited[R][C];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int res;
queue <pair<int, int>> q;
vector <pair<int, int>> v;
void BFS(char now)
{
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= R || ny >= C || visited[nx][ny]) continue;
			if (board[nx][ny] != now) continue;
			q.push({ nx,ny });
			v.push_back({ nx,ny });
			visited[nx][ny] = true;
		}
	}
}
bool find()
{
	bool flag = false;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (!visited[i][j] && board[i][j] != '.')
			{
				q.push({ i,j });
				BFS(board[i][j]);
			}
			if (v.size() >= 4)
			{
				for (int k = 0; k < v.size(); k++)
				{
					board[v[k].X][v[k].Y] = '.';
					flag = true;
				}
			}
			v.clear();
		}
	}

	return flag;
}
void move()
{
	int idx = 0;
	char board2[R];

	for (int i = 0; i < C; i++)
	{
		fill(board2, board2 + R, '.');
		idx = 0;
		for (int j = 0; j < R; j++)
		{
			if (board[j][i] != '.')
				board2[idx++] = board[j][i];
		}

		for (int j = R - 1; j >= 0; j--)
		{
			if (idx <= 0) board[j][i] = '.';
			else
			board[j][i] = board2[--idx];
		}
	}

}
void input()
{
	string str = "";
	for (int i = 0; i < R; i++)
	{
		cin >> str;
		for (int j = 0; j < C; j++)
			board[i][j] = str[j];
	}

}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	bool flag;
	input();
	while (true)
	{
		flag = find();
		move();
		if (flag == false) break;
		res++;
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				visited[i][j] = false;
	}
	cout << res;
}