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
						L1 = { i,j }; // 백조 1번
						q.push({ i,j }); // 큐의 시작위치
						vis[i][j] = true;
						flag = true;
					}
					else
						L2 = { i,j };
				}
				if (board[i][j] != 'X')
				{
					sub.push({ i,j }); // sub 큐의 시작 원소들
				}
			}
		}
	}
	int solve()
	{
		int day = 0;

		while (true)
		{
			while (!sub2.empty()) // 빙판과 맞닿은 점들
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
					if (board[nx][ny] == 'X') // 빙판과 맞닿아있다면 sub2에 push하고 이 큐가 끝나고 다음 외부
												//while이 돌때 q로 이동
					{
						sub2.push({ cur.X,cur.Y });
						continue;
					}
					vis[nx][ny] = true;
					q.push({ nx,ny });
				}
			}

				int t = sub.size();
				while (t--) // sub 큐의 개수만큼만 반복하기
				{
					auto cur = sub.front(); sub.pop();
					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];

						if (nx < 0 || ny < 0 || nx >= r || ny >= c || Copy[nx][ny]) continue;

						if (board[nx][ny] == 'X') // 빙판이면 녹이고 Copy를 true로 변경 - 방문함
						{
							Copy[nx][ny] = true;
							sub.push({ nx,ny });
							board[nx][ny] = '.';
						}
					}
				}

				day++;
			

			/*for (int i = 0; i < r; i++) // 이 문장이 없어도 정답처리되며, 오히려 없어야함
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