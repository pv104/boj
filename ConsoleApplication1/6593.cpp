#include <iostream>
#include <queue>
#include <tuple>
#include <string>
using namespace std;
#define MAX 32
#define WALL -1
#define SPACE 0
int l, r, c;
int dz[2] = { 1,-1 };
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int board[MAX][MAX][MAX];
tuple <int, int, int> finish;
queue <tuple<int, int, int>> q;
void input()
{

	char t;
	cin >> l >> r >> c;
	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < r; j++)
		{
			for (int k = 0; k < c; k++)
			{
				cin >> t;
				if (t == 'S')
				{
					board[i][j][k] = SPACE;
					q.push({ i,j,k });
				}
				else if (t == '.')
				{
					board[i][j][k] = SPACE;
				}
				else if (t == '#')
				{
					board[i][j][k] = WALL;
				}
				else if (t == 'E')
				{
					board[i][j][k] = SPACE;
					finish = { i,j,k };
				}
			}

		}
	}
}
string solve()
{
	int result = 0;
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		if (board[get<0>(finish)][get<1>(finish)][get<2>(finish)])
			break;

		for (int i = 0; i < 2; i++)
		{
			int nz = get<0>(cur) + dz[i];
			int nx = get<1>(cur);
			int ny = get<2>(cur);
			if (nz < 0 || nz >= l || nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (board[nz][nx][ny]) continue;
			board[nz][nx][ny] = board[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
			q.push({ nz,nx,ny });

		}
			for (int j = 0; j < 4; j++)
			{
				int nz = get<0>(cur);
				int nx = get<1>(cur) + dx[j];
				int ny = get<2>(cur) + dy[j];
				if (nz < 0 || nz >= l || nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
				if (board[nz][nx][ny]) continue;
				board[nz][nx][ny] = board[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
				q.push({ nz,nx,ny });
			}
	}

	result = board[get<0>(finish)][get<1>(finish)][get<2>(finish)];
	if (!result) return "Trapped!";
	else return "Escaped in " + to_string(result) + " minute(s).";
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	while (true)
	{
		input();
		if (l == 0 && r == 0 && c == 0) return 0;
		cout << solve() << "\n";
		while (!q.empty()) q.pop();
	}
}