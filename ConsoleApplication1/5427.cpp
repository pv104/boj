#include <iostream>
#include <queue>
#include <string>
using namespace std;
#define X first
#define Y second
#define MAX 1005
#define FIRE -2
#define WALL -1
#define SPACE 0
#define HUMAN 1
int W, H;
int board[MAX][MAX], fboard[MAX][MAX];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue <pair<int, int>> h, f;
void input()
{
	char c;
	for (int i = 0; i < MAX; i++)
		fill(board[i], board[i] + MAX, SPACE);

	for (int i = 0; i < MAX; i++)
		fill(fboard[i], fboard[i] + MAX, SPACE); // �迭�� �����̹ǰ� �׽�Ʈ ���̽��� �������̹Ƿ� �ʱ�ȭ
	cin >> H >> W;
	for (int i = 0; i < W; i++)
	{
		for (int j = 0; j < H; j++)
		{
			cin >> c;
			if (c == '*')
			{
				board[i][j] = FIRE;
				fboard[i][j] = HUMAN;
				f.push({ i,j });
			}
			else if (c == '#')
			{
				board[i][j] = WALL;
				fboard[i][j] = WALL;
			}
			else if (c == '.')
				board[i][j] = SPACE;
			else // HUMAN
			{
				board[i][j] = HUMAN;
				h.push({ i,j });
			}
		}
	}
}
string solve()
{
	// �� ���� ������ �κ�
	// ���� ���� ���������� ������, �� ������ �ƴϸ� �̹� �ҷ� �����ִ� ���� ��� ť�� �־ �޸𸮰� ����
	// ���� �� ������ ���� ť�� ����
	while (!f.empty())
	{
			pair <int, int> cur = f.front(); f.pop();
			for (int dir = 0; dir < 4; dir++)
			{
				int tx = cur.X + dx[dir];
				int ty = cur.Y + dy[dir];
				if (tx < 0 || tx >= W || ty < 0 || ty >= H) continue;
				if (fboard[tx][ty] != SPACE) continue;
				fboard[tx][ty] = fboard[cur.X][cur.Y]+1;
				f.push({ tx,ty });
			}

	}
	// ����� �κ�
	// ����̴� 1���� �����ϹǷ� �������ǿ� ���� +1�� ������ �ʾƵ� ��
	
	while(!h.empty())
	{
		
			pair <int, int> cur = h.front(); h.pop();
			if (cur.X == 0 || cur.X == W - 1 || cur.Y == 0 || cur.Y == H - 1)

				return to_string(board[cur.X][cur.Y]);
			for (int dir = 0; dir < 4; dir++)
			{
				int tx = cur.X + dx[dir];
				int ty = cur.Y + dy[dir];
				if (tx < 0 || tx >= W || ty < 0 || ty >= H) continue;
				if (board[tx][ty] != SPACE) continue; // �� ������ �ƴϸ� �� �� ����
				if (board[cur.X][cur.Y] + 1 < fboard[tx][ty] || fboard[tx][ty] == SPACE) 
					// �̹� ���� �پ��ų�, ������ ���� �Ű��� ĭ���δ� �� �� �����Ƿ�
					// ���� ��ġ +1�ʺ��� ���� �����ϴ� �ð��� �ʾ�� �� �� ����
					// �� ��° ������ ���� �ƿ� ���� ��츦 ������� ��, �� ������ �״�� ���������Ƿ�
					// �� BFS�� ������ �� �Ŀ��� �� ������ �ִٸ� -> ���� �ƿ� ���� ���
				{
					board[tx][ty] = board[cur.X][cur.Y] + 1;
					h.push({ tx,ty });
				}
			}
		
		
	}

	return "IMPOSSIBLE";
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		input();
		cout << solve() << "\n";

		while (!h.empty()) h.pop();
		while (!f.empty()) f.pop();
		
	}
}