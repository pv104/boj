#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 22
int n, m, x, y, k;
int board[MAX][MAX], dice[4][3];
int dx[5] = { 0,0,0,-1,1 }; // [0] 안쓰고, [1] = 동, [2] = 서, [3] = 북, [4] = 남
int dy[5] = { 0,1,-1,0,0 };	
void input()
{
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
}
void roll(int dir)
{
	int x[4];
	if (dir == 1)
	{
		x[0] = dice[1][1];
		x[1] = dice[1][2];
		x[2] = dice[3][1];
		x[3] = dice[1][0];

		dice[1][2] = x[0];
		dice[3][1] = x[1];
		dice[1][0] = x[2];
		dice[1][1] = x[3];
	}
	else if (dir == 2)
	{
		x[0] = dice[1][1];
		x[1] = dice[1][0];
		x[2] = dice[3][1];
		x[3] = dice[1][2];

		dice[1][0] = x[0];
		dice[3][1] = x[1];
		dice[1][2] = x[2];
		dice[1][1] = x[3];
	}
	else if (dir == 3)
	{
		x[0] = dice[0][1];
		x[1] = dice[1][1];
		x[2] = dice[2][1];
		x[3] = dice[3][1];

		dice[3][1] = x[0];
		dice[0][1] = x[1];
		dice[1][1] = x[2];
		dice[2][1] = x[3];
	}
	else if (dir == 4)
	{
		x[0] = dice[0][1];
		x[1] = dice[1][1];
		x[2] = dice[2][1];
		x[3] = dice[3][1];

		dice[1][1] = x[0];
		dice[2][1] = x[1];
		dice[3][1] = x[2];
		dice[0][1] = x[3];
	}


}
int solve(int dir)
{
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	if (nx < 0 || ny < 0 || nx >= n || ny >= m) return -1;
	roll(dir);
	if (board[nx][ny] == 0) board[nx][ny] = dice[3][1];
	else
	{
		dice[3][1] = board[nx][ny];
		board[nx][ny] = 0;
	}	
	x = nx, y = ny;
	return dice[1][1];
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	for (int count = 0; count < k; count++)
	{
		int dir;
		cin >> dir;
		int res = solve(dir);

		if (res >= 0) cout << res << "\n";
	}
}