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
		fill(fboard[i], fboard[i] + MAX, SPACE); // 배열이 전역이므고 테스트 케이스가 여러개이므로 초기화
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
	// 불 먼저 돌리는 부분
	// 불은 따로 종료조건이 없지만, 빈 공간이 아니면 이미 불로 덮혀있는 곳을 계속 큐에 넣어서 메모리가 터짐
	// 따라서 빈 공간일 때만 큐에 넣음
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
	// 상근이 부분
	// 상근이는 1부터 시작하므로 종료조건에 따로 +1을 해주지 않아도 됨
	
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
				if (board[tx][ty] != SPACE) continue; // 빈 공간이 아니면 갈 수 없음
				if (board[cur.X][cur.Y] + 1 < fboard[tx][ty] || fboard[tx][ty] == SPACE) 
					// 이미 불이 붙었거나, 다음에 불이 옮겨질 칸으로는 갈 수 없으므로
					// 현재 위치 +1초보다 불이 도착하는 시간이 늦어야 갈 수 있음
					// 두 번째 조건은 불이 아예 없는 경우를 고려했을 때, 빈 공간이 그대로 남아있으므로
					// 불 BFS를 돌리고 난 후에도 빈 공간이 있다면 -> 불이 아예 없는 경우
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