#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
#define MAX 1002
#define PMAX 12
#define WALL -1
#define SPACE 0
int board[MAX][MAX];
bool vis[MAX][MAX];
int S[PMAX];
int res[PMAX];
int n, m, s, p;
queue <tuple<int, int, int>> q[PMAX];
queue <tuple<int, int, int>> q2[PMAX];
void input()
{
	cin >> n >> m >> p;
	char c;
	for (int i = 1; i <= p; i++)
	{
		cin >> S[i];
		if (S[i] > 1000002) S[i] = 1000002;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> c;
			if (c == '.')
				board[i][j] = SPACE;
			else if (c == '#')
				board[i][j] = WALL;
			else
			{
				board[i][j] = c - '0';
			}
		}
	}
}
void findCastle()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (board[i][j] < 1 || board[nx][ny] != 0) continue;
				if (vis[i][j]) continue;
				q[board[i][j]].push({ i,j,0});
				vis[i][j] = true;
			}
		}
	}
}
bool isEmpty()
{
	for (int i = 1; i <= p; i++)
		if (!q[i].empty()) return false;
	return true;
}
int solve()
{
	findCastle(); // 큐에 넣기
	while (true)
	{
		if (isEmpty())
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					int num = board[i][j];
					if (board[i][j] > 0)
						res[num]++;
				}
			}
			return 0;
		}

		for (int i = 1; i <= p; i++)
		{
			while (!q[i].empty())
			{
				int x, y, now;
				tie(x, y, now) = q[i].front(); q[i].pop();
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
					if (board[nx][ny] != 0) continue;
					if (now < S[i]) // S번째 플레이어가 이동할 수 있는 거리보다 작을 때만 push
					{
						q[i].push({ nx,ny,now + 1 });
						board[nx][ny] = i;
					}
					else
					{
						q2[i].push({ x,y,0 });
					}
				}
			}

			while (!q2[i].empty())
			{
				q[i].push(q2[i].front());
				q2[i].pop();
			}

		}
	}




}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	solve();
	for (int i = 1; i <= p; i++)
		cout << res[i] << ' ';
}