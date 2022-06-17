#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define X first
#define Y second
#define MAX 102
int trueBoard[MAX][MAX];
int board[MAX][MAX];
bool vis[MAX][MAX];
int n;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
queue <pair<int, int>> q;
void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> trueBoard[i][j];
}
int solve()
{
	int res = 0;
	for (int k = 0; k <= 100; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (trueBoard[i][j] <= k)
					board[i][j] = -1; // 이미 침수됨
				else board[i][j] = 0; // 보드 초기값 설정
				vis[i][j] = false;
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] == -1 || vis[i][j] == true) continue;
				q.push({ i,j });
				cnt++;
				while (!q.empty())
				{
					auto cur = q.front(); q.pop();
					vis[cur.X][cur.Y] = true;
					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if (board[nx][ny] != 0 || vis[nx][ny] == true) continue;
						board[nx][ny] = 1;
						vis[nx][ny] = true;
						q.push({ nx,ny });
					}
				}
				
			}
		}
		res = max(res, cnt);
	}
	return res;
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	input(); cout << solve();
}