#include <iostream>
#include <queue>
using namespace std;
#define MAX 302
#define X first
#define Y second
#define ICE 0
int board[MAX][MAX];
int iceBoard[MAX][MAX];
bool check[MAX][MAX];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m, bergCnt, cnt;
queue <pair<int, int>> q;
void input()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j]) bergCnt++;
		}
	}
}
void init()
{
	for (int i = 0; i < n; i++)
	{
		fill(iceBoard[i], iceBoard[i] + MAX, 0);
		fill(check[i], check[i] + MAX, false);
	}
}
void melting()
{
	for (int i = 0; i < n; i++) // ���� ������ 0�� � �ִ��� üũ
	{
		for (int j = 0; j < m; j++)
		{
			int iceCnt = 0;
			if (board[i][j] == ICE) continue;
			q.push({ i,j });
			auto cur = q.front(); q.pop();
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (board[nx][ny] == ICE) iceCnt++;
			}

			iceBoard[cur.X][cur.Y] += iceCnt;

		}
	}

	for (int i = 0; i < n; i++) // üũ�� ������ŭ ���̱�
	{
		for (int j = 0; j < m; j++)
		{
			if (iceBoard[i][j] != 0)
			{
				board[i][j] -= iceBoard[i][j];
				if (board[i][j] <= 0)
				{
					board[i][j] = 0;
					bergCnt--;
				}
			}
		}
	}
}
void onePointBFS()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j]) // board[i][j]�� �����̸�
			{
				q.push({ i,j }); // ������ ���� �ֱ�
				break;
			}
			if (q.size() != 0) break;
		}
	}
	while (!q.empty()) // ������ 1���� �����ϰ� ������ �̾����ִ��� Ȯ��
	{
		auto cur = q.front(); q.pop();
		check[cur.X][cur.Y] = true;
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (check[nx][ny] || !board[nx][ny]) continue;
			check[nx][ny] = true;
			q.push({ nx,ny });
		}

	}
}
bool checking()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] && !check[i][j]) return true; // ������ �ִµ� BFS�� �湮���� ���� ��� 
														// = ������ ������ ���
		}
	}
	return false;
}
int solve()
{
	while (bergCnt != 0)
	{
		melting();
		cnt++; // 1�� ����

		if (bergCnt == 1) return cnt; // ���� ������ 1���� ����
		onePointBFS();
		if (checking()) return cnt;
		init();
	}
	return 0;
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	input(); cout << solve();
}