#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define X first
#define Y second
#define MAX 105
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int m, n, k;
queue <pair<int, int>> Main, sub;
int board[MAX][MAX];
bool visited[MAX][MAX];
vector <int> res;
void input()
{
	int x1, y1, x2, y2;
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++)
	{
		// x와 y좌표 반대로 쓰는거 조심하기
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1; i < y2; i++)
		{
			for (int j = x1; j < x2; j++)
				board[i][j] = 1;
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{	// 미리 후보가 될 수 있는 시작점들을 넣어둠 (혹은 2중 for문으로 바로 넣고 돌려도 됨 -> 바킹독님 코드)
			if (board[i][j] == 0)
				Main.push({ i,j });
		}
	}

}
void solve()
{
	while (!Main.empty())
	{
		
		pair<int, int> t = Main.front(); Main.pop();
		//정점이 중복될 수 있으므로 방문하지 않은 정점만 처리
		if (!visited[t.X][t.Y])
		{
			visited[t.X][t.Y] = true;
			sub.push(t);
			int cnt = 1; // 1부터 시작하는 이유-> 이미 시작점을 방문하는 순간 넓이가 1임
			while (!sub.empty())
			{
				pair<int, int> cur = sub.front(); sub.pop();
			
				for (int dir = 0; dir < 4; dir++)
				{
					int tx = cur.X + dx[dir];
					int ty = cur.Y + dy[dir];
					if (tx < 0 || tx >= m || ty < 0 || ty >= n) continue;
					if (board[tx][ty] == 1 || visited[tx][ty] == true) continue;
					visited[tx][ty] = true;
					sub.push({ tx,ty });
					cnt++; // 조건이 맞았다면 넓이 1 증가시키기
					
				}

			}

			res.push_back(cnt); // sub가 끝났다는것은 영역 하나 처리가 끝났다는 것 -> 정답 추가
			
		}
	}
	
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	solve();
	cout << res.size() << "\n";
	sort(res.begin(), res.end());
	for (auto i : res)
		cout << i << ' ';
}