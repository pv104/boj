#include <iostream>
#include <queue>
using namespace std;
#define MAX 200005
#define INF 987654321
queue <int> q;
int board[MAX];
int n, k;
void input()
{
	cin >> n >> k;
	fill(board, board + MAX, INF);
	board[n] = 0;
	board[k] = -1;
	q.push(n);
}
int solve()
{
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		if (cur == k || cur-1 == k || cur+1 == k || cur*2 == k) return board[cur] + 1;

		if (board[cur] < board[cur - 1])
		{
			board[cur - 1] = board[cur] + 1;
			q.push(cur - 1);
		}if (board[cur] < board[cur + 1])
		{
			board[cur + 1] = board[cur] + 1;
			q.push(cur + 1);
		}if ((cur * 2 < MAX) && board[cur] < board[cur * 2] )
		{
			board[cur * 2] = board[cur] + 1;
			q.push(cur * 2);
		}
	}
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	input();
	cout << solve();
}