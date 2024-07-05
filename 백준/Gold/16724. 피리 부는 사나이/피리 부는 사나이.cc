#include <iostream>
#include <string>
using namespace std;
#define SIZE 1003
#define pii pair<int,int>
#define Y first
#define X second
int N, M, res, cnt;
int p[SIZE*SIZE];
int board[SIZE][SIZE];
int visited[SIZE][SIZE];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
string S;
void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> S;
		for (int j = 0; j < M; j++)
		{
			int cur = 0;
			if (S[j] == 'R')
				cur = 1;
			else if (S[j] == 'D')
				cur = 2;
			else if (S[j] == 'L')
				cur = 3;
			board[i][j] = cur;
		}
	}
}
void dfs(int r, int c) {
	visited[r][c] = 1;
	int dir = board[r][c];
	int nr = r + dy[dir];
	int nc = c + dx[dir];
	if (visited[nr][nc] == 1) res++;
	// 지나가면서 같은 경로로 설정하기
	if (visited[nr][nc] == 0)
	dfs(nr, nc);
	visited[r][c] = 2;
	return;
}
int solve() {

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visited[i][j] == 0)
			dfs(i, j);
		}
	}

	return res;
}
int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	input();
	cout << solve();
}