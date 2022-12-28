#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#define MAX 103
#define X first
#define Y second
using namespace std;
int idx, dir, n, k, l, now, sec;
vector <pair<int, int>> v;
deque <pair<int, int>> dq;
int board[MAX][MAX];
int move()
{
	auto cur = dq.front();
	int x = cur.X;
	int y = cur.Y;
	if (dir == 0)
	{
		x += -1;
	}
	else if (dir == 1)
	{
		y += 1;
	}
	else if (dir == 2)
	{
		x += 1;
	}
	else
		y += -1;
	if (x < 1 || y < 1 || x > n || y > n) return 1;
	for (auto cur = dq.begin() + 1; cur != dq.end(); cur++)
	{
		if (x == cur->X && y == cur->Y) return 1;
	}
	if (board[x][y])
	{
		board[x][y] = 0;
	}
	else
		dq.pop_back();
	dq.push_front({x,y});
	return 0;
}
void input()
{
	int x, y;
	int r;
	char d;
	dq.push_front({ 1,1 });
	dir = 1;
	cin >> n;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> x >> y;
		board[x][y] = 1;
	}
	cin >> l;
	for (int i = 0; i < l; i++)
	{
		cin >> r >> d;
		if (d == 'L')
			v.push_back({ r,0 });
		else
			v.push_back({ r,1 });
	}
}
void rotate(int direction)
{
	if (direction == 0) // 왼쪽
	{
		if (dir == 0)
			dir = 3;
		else dir--;
	}
	else // 오른쪽
	{
		if (dir == 3)
			dir = 0;
		else dir++;
	}
}
int solve()
{
	while (true)
	{
		if (move() > 0) return sec + 1;
		else sec++;
		if (idx < v.size())
		{
			if (v[idx].X == sec)
			{
				rotate(v[idx++].Y);
			}
		}
	}
}

int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	cout << solve();
}