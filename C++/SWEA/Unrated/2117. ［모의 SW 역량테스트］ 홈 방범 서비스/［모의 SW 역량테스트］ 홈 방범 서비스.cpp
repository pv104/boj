#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
#define SIZE 22
#define Y first
#define X second
#define pii pair<int,int>
int N, M, T, res;
int board[SIZE][SIZE];
int costs[SIZE];
bool visited[SIZE][SIZE];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
void init() {
	res = 0;
	memset(board, 0, sizeof(board));
	memset(visited, false, sizeof(visited));
}
void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
		}
	}
}
void bfs(int r, int c) {
	queue <pii> q;
	q.push({ r,c });
	visited[r][c] = true;
	int k = 2, size, t = board[r][c], cost = 0, profits = 0;
	res = max(res, t);
	while (true)
	{
		if (k > 21) return;
		size = q.size();
		while (size-- > 0)
		{
			auto cur = q.front(); q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int ny = cur.Y + dy[dir];
				int nx = cur.X + dx[dir];
				if (ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx]) continue;
					//cout << " ny : " << ny << " nx : " << nx << " t : " << t << " k : " << k << "\n";
				if (board[ny][nx])
					t++;
				visited[ny][nx] = true;
				q.push({ ny,nx });
			}
		}
		profits = t * M;
		/*cout << "q.size() : " << q.size() << "\n";*/
		if (profits >= costs[k++])
		{
			res = max(res, t);
			//cout << " r : " << r << " c : " << c;
			//cout << " k : " << k << " res : " << res << "\n";
		}
	}
}
int solve() {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			bfs(i, j);
			memset(visited, false, sizeof(visited));
		}
	}
	return res;
}
int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	/*FILE* stream;
	freopen_s(&stream, "input.txt", "r", stdin);
	freopen_s(&stream, "output.txt", "w", stdout);*/
	cin >> T;
	for (int i = 1; i < SIZE; i++)
	{
		int val = (i*i) + (i - 1)*(i - 1);
		costs[i] = val;
	}

	for (int TC = 1; TC <= T; TC++)
	{
		init();
		input();
		cout << "#" << TC << " " << solve() << "\n";
	}
}