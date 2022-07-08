#include <iostream>
#include <queue>
using namespace std;
#define MAX 102
#define X first
#define Y second
queue <pair<int, int>> Switch[MAX][MAX];
queue <pair<int, int>> q;
bool vis[MAX][MAX], light[MAX][MAX];
int x, y, a, b, n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
void input()
{

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> a >> b;
		Switch[x][y].push({ a,b });
	}
}
int solve()
{
	int res = 1;
	light[1][1] = true;
	while (true)
	{
		int cnt = 0;
		q.push({ 1,1 });
		vis[1][1] = true;
		while (!q.empty())
		{
			auto cur = q.front(); q.pop();
			while (!Switch[cur.X][cur.Y].empty())
			{
				auto t = Switch[cur.X][cur.Y].front(); Switch[cur.X][cur.Y].pop();
				
				cnt++;
				if (light[t.X][t.Y] == false)
				{
					res++;
					light[t.X][t.Y] = true;
				}
			}
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];

				if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
				if (vis[nx][ny] || !light[nx][ny]) continue;
				q.push({ nx,ny });
				vis[nx][ny] = true;
			}
		}
		if (cnt == 0) return res;
		for (int i = 0; i < MAX; i++)
			fill(vis[i], vis[i] + MAX, false);
	}
	return res;
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);

	input();
	cout << solve();
}