#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 987654321
#define MAX 102
#define X first
#define Y second
#define SEA 0
#define LAND -1
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int board[MAX][MAX], vis[MAX][MAX], sqvis[MAX][MAX];
queue <pair<int, int>> q, sq;
int n;
bool check(int x, int y)
{
	if (x < 0 || y < 0 || x >= n || y >= n) return true;
	return false;
}
void input()
{
	int t;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> t;
			if (t == 0) board[i][j] = SEA;
			else board[i][j] = LAND;
		}
	}
}
int solve()
{

	int res = INF;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] >= 0 || vis[i][j])
				continue;
			q.push({ i,j });
			while (!q.empty())
			{
				auto cur = q.front(); q.pop();
				int x = cur.X, y = cur.Y;
				vis[x][y] = true;
				for (int dir = 0; dir < 4; dir++)
				{

					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if (check(nx, ny)) continue;
					if (board[nx][ny] == SEA && !sqvis[nx][ny]) // ���� �湮���� ���� �ٴٶ��
					{
						sqvis[nx][ny] = true;
						sq.push({ nx,ny });
					}
					if (board[nx][ny] == LAND && !vis[nx][ny]) // ���� �湮���� ���� ����� ��
					{
						vis[nx][ny] = true;
						q.push({ nx,ny });
					}

				}
			}

				while (!sq.empty()) // �ٴٿ��� �ٸ� ������ �̾����� ��� Ž��
				{
					auto cur = sq.front(); sq.pop();
					int x = cur.X, y = cur.Y;

					for (int dir = 0; dir < 4; dir++)
					{
						int nx = x + dx[dir];
						int ny = y + dy[dir];
						if (check(nx, ny)) continue;
						if (vis[nx][ny] || sqvis[nx][ny]) continue; // �̹� �湮�� ���̰ų�, �湮�� �ٴٸ� continue

						if (board[nx][ny] == LAND)					// ������ �����ߴٸ�
						{											// �ٸ� ������ �ٸ��� ���������� �ǹ��ϴµ�,
																	// BFS�� ��� ��θ� �� ã���鼭 ���ϱ�
																	// ���� ���� ã�� ��ΰ� �ִܰ����
							
							res = min(res, board[x][y] + 1);
							while (!sq.empty())
								sq.pop();
							break;
						}
						sqvis[nx][ny] = true;
						board[nx][ny] = board[x][y] + 1;
						sq.push({ nx,ny });
					}
				}
			
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					sqvis[i][j] = false;
					if (board[i][j] > 0) board[i][j] = 0; // board�� �̿��ؼ� �Ÿ��� ��������Ƿ� �ʱ�ȭ!!!
				}
			}
		}


	}

	return res;
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	cout << solve();
}