#include <iostream>
#include <queue>
#include <string>
using namespace std;
#define MAX 1000005
int f, s, g, u, d;
int board[MAX];
queue <int> q;
void input()
{
	cin >> f >> s >> g >> u >> d;
	q.push(s);
}
string solve()
{
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		if (cur == g) return to_string(board[cur]);
		if (d != 0 && (cur - d) > 0 && (board[cur - d] == 0))
		{
			board[cur - d] = board[cur] + 1;
			q.push(cur - d);
		}
		if (u != 0 && (cur + u) <= f && (board[cur + u] == 0))
		{
			board[cur + u] = board[cur] + 1;
			q.push(cur + u);
		}
	}
	return "use the stairs";
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	cout << solve();
}