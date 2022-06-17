#include <iostream>
#include <queue>
#include <math.h>
using namespace std;
#define MAX 305
#define X first
#define Y second
int board[MAX][MAX];
int dx[8] = { 2,1,-1,-2,-2,-1,1,2 };
int dy[8] = { 1,2,2,1,-1,-2,-2,-1 };
int t,l;
pair <int, int> n, k;
void input(queue <pair<int,int>> &q)
{
	for (int i=0; i<MAX; i++)
	fill(board[i], board[i] + MAX, -1);
	cin >> l;
	cin >> n.X >> n.Y;
	cin >> k.X >> k.Y;
	board[n.X][n.Y] = 0;
	q.push(n);
}
int solve()
{

	queue <pair<int, int>> q;
	input(q);
	while (board[k.X][k.Y] == -1)
	{
		pair <int, int> cur = q.front(); q.pop();
		for (int dir = 0; dir < 8; dir++)
		{
			int tx = cur.X + dx[dir];
			int ty = cur.Y + dy[dir];
			if (tx < 0 || tx >= l || ty < 0 || ty >= l || board[tx][ty] != -1) continue;
			board[tx][ty] = board[cur.X][cur.Y] + 1;
			q.push({ tx,ty });
		}
	}
	return board[k.X][k.Y];
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> t;
	while (t--)
	{
		cout << solve() << "\n";
	}
}