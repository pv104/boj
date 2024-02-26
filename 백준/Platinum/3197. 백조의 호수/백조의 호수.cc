	#include <iostream>
	#include <queue>
	using namespace std;
	#define MAX 1502
	#define X first
	#define Y second
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	queue <pair<int, int>> q, sub, sub2;
	char board[MAX][MAX];
	bool vis[MAX][MAX],Copy[MAX][MAX];
	int r, c;
	pair <int, int> L1, L2;
	void input()
	{
		bool flag = false;
		cin >> r >> c;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cin >> board[i][j];
				if (board[i][j] == 'L')
				{
					if (!flag)
					{
						L1 = { i,j };
						q.push({ i,j });
						vis[i][j] = true;
						flag = true;
					}
					else
						L2 = { i,j };
				}
				if (board[i][j] != 'X')
				{
					sub.push({ i,j });
				}
			}
		}
	}
	int solve()
	{
		int day = 0;

		while (true)
		{
			while (!sub2.empty()) // 
			{
				q.push(sub2.front()); sub2.pop();
			}
			while (!q.empty())
			{
				auto cur = q.front(); q.pop();
				if (cur.X == L2.X && cur.Y == L2.Y)
					return day;
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || ny < 0 || nx >= r || ny >= c || vis[nx][ny]) continue;
					if (board[nx][ny] == 'X')
					{
						sub2.push({ cur.X,cur.Y });
						continue;
					}
					vis[nx][ny] = true;
					q.push({ nx,ny });
				}
			}

				int t = sub.size();
				while (t--)
				{
					auto cur = sub.front(); sub.pop();
					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];

						if (nx < 0 || ny < 0 || nx >= r || ny >= c || Copy[nx][ny]) continue;

						if (board[nx][ny] == 'X')
						{
							Copy[nx][ny] = true;
							sub.push({ nx,ny });
							board[nx][ny] = '.';
						}
					}
				}

				day++;
			

			/*for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < c; j++)
				{
					if (Copy[i][j])
					{
						board[i][j] = '.';
						Copy[i][j] = false;
					}
				}
			}*/
		
		}
	}
	int main()
	{
		cin.tie(0); ios::sync_with_stdio(0);
		input(); cout << solve();
	}