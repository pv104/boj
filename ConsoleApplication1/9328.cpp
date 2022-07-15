#include <iostream>
#include <queue>
using namespace std;
#define X first
#define Y second
#define MAX 102
char board[MAX][MAX];
bool vis[MAX][MAX],door[26];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue <pair<int, int>> q;
queue <pair<int, int>> sub;
int w, h, t;
string str;
void input()
{
	for (int i = 0; i < MAX; i++)
	{
		fill(vis[i], vis[i] + MAX, false); // 방문한 점 초기화
		fill(board[i], board[i] + MAX, '*');
	}
	for (int i = 0; i < 26; i++)
		door[i] = false;
	while (!q.empty()) q.pop();
	cin >> h >> w;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> board[i][j];
		}
	}
	cin >> str;
	if (str[0] == '0') return;
	int len = str.length();
	for (auto i : str)
		door[i - 'a'] = true;

	
}
bool isOpen(int i,int j)
{
	if (board[i][j] >= 'A' && board[i][j] <= 'Z')
		if (!door[board[i][j] - 'A']) return false;
	if (board[i][j] == '*') return false;
	if (i == 0 || j == 0 || i == h - 1 || j == w - 1) return true;
	return false;
}
int solve()
{
	int res = 0;
	int cnt = 1, t = 1;
	while (t != 0)
	{
		t = 0;
		for (int i = 0; i < MAX; i++)
			fill(vis[i], vis[i] + MAX, false); // 방문한 점 초기화
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (isOpen(i, j))
					{
						q.push({ i,j });
						vis[i][j] = true;
						if (board[i][j] >= 'a' && board[i][j] <= 'z')
							door[board[i][j] - 'a'] = true;
						if (board[i][j] == '$')
						{
							res++;
							board[i][j] = '.';
						}
					}	

					while (!q.empty())
					{
						auto cur = q.front(); q.pop();
						int x = cur.X;
						int y = cur.Y;

						for (int dir = 0; dir < 4; dir++)
						{
							int nx = dx[dir] + cur.X;
							int ny = dy[dir] + cur.Y;
							if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
							if (vis[nx][ny] || board[nx][ny] == '*') continue;
							if (board[nx][ny] == '.')
							{
								q.push({ nx,ny });
								vis[nx][ny] = true;
							}
							else if (board[nx][ny] == '$')
							{
									res++;
									board[nx][ny] = '.';
								q.push({ nx,ny });
								vis[nx][ny] = true;
							}
							else if (board[nx][ny] >= 'A' && board[nx][ny] <= 'Z') // 문이라면
							{
								if (door[board[nx][ny] - 'A']) // 열 수 있는 문이라면
								{
									q.push({ nx,ny });
									vis[nx][ny] = true;
								}
							}
							else if (board[nx][ny] >= 'a' && board[nx][ny] <= 'z') // 열쇠라면
							{
								
									t++;
								door[board[nx][ny] - 'a'] = true;
								q.push({ nx,ny });
								vis[nx][ny] = true;
								board[nx][ny] = '.';
							}
						}
					}
			
						

					
				
				
			}
		}
	}
	
	return res;
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		input(); cout << solve() << "\n";
		
	
	}
}