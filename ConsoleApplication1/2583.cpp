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
		// x�� y��ǥ �ݴ�� ���°� �����ϱ�
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
		{	// �̸� �ĺ��� �� �� �ִ� ���������� �־�� (Ȥ�� 2�� for������ �ٷ� �ְ� ������ �� -> ��ŷ���� �ڵ�)
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
		//������ �ߺ��� �� �����Ƿ� �湮���� ���� ������ ó��
		if (!visited[t.X][t.Y])
		{
			visited[t.X][t.Y] = true;
			sub.push(t);
			int cnt = 1; // 1���� �����ϴ� ����-> �̹� �������� �湮�ϴ� ���� ���̰� 1��
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
					cnt++; // ������ �¾Ҵٸ� ���� 1 ������Ű��
					
				}

			}

			res.push_back(cnt); // sub�� �����ٴ°��� ���� �ϳ� ó���� �����ٴ� �� -> ���� �߰�
			
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