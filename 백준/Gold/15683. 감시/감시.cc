#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define X first
#define Y second
#define MAX 10
#define INF 987654321
int Dboard[MAX][MAX];
vector <pair<pair<int, int>, int>> v;
int n, m, res = INF;
void Input(int i, int j, int t,int board[][MAX])
{
	if (t == 0) // 위로
	{
		while (i >= 0 && board[i][j] <= 5)
		{
			if (board[i][j] == 0)
				board[i][j] = -1;
			i--;
		}
	}
	else if (t == 1) // 오른쪽
	{
		while (j < m && board[i][j] <= 5)
		{
			if (board[i][j] == 0)
				board[i][j] = -1;
			j++;
		}
	}
	else if (t == 2) // 아래
	{
		while (i < n && board[i][j] <= 5)
		{
			if (board[i][j] == 0)
				board[i][j] = -1;
			i++;
		}
	}
	else // 왼쪽
	{
		while (j >= 0 && board[i][j] <= 5)
		{
			if (board[i][j] == 0)
				board[i][j] = -1;
			j--;
		}
	}
}
void solve(int c,int rot,int board[][MAX])
{
	int Tboard[MAX][MAX];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			Tboard[i][j] = board[i][j];
	if (v.size() <= c) return;

		auto cur = v[c];
		int x = cur.X.X;
		int y = cur.X.Y;
		int t = cur.Y;
		int cnt = 0;
		
		if (t == 1)
		{
			Input(x, y, rot,Tboard);
		}
		else if (t == 2)
		{
			
			if (rot % 2 == 0)
			{
				Input(x, y, 0,Tboard);
				Input(x, y, 2,Tboard);

			}
			else
			{
				Input(x, y, 1,Tboard);
				Input(x, y, 3,Tboard);
			}
		}
		else if (t == 3)
		{
			
			Input(x, y, rot,Tboard);
			Input(x, y, (rot + 1) % 4,Tboard);

		}
		else if (t == 4)
		{
			
			Input(x, y, rot,Tboard);
			Input(x, y, (rot + 1) % 4,Tboard);
			Input(x, y, (rot + 2) % 4,Tboard);
		}
		else
		{

			Input(x, y, 0,Tboard);
			Input(x, y, 1,Tboard);
			Input(x, y, 2,Tboard);
			Input(x, y, 3, Tboard);
		}

		if (v.size() - 1 == c)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (!Tboard[i][j])
						cnt++;
				}
			}

			res = min(res, cnt);
			return;
		}
		for (int i = 0; i < 4; i++)
			solve(c + 1, i, Tboard);
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> Dboard[i][j];
			if (Dboard[i][j] > 0 && Dboard[i][j] < 6) v.push_back( { {i, j}, Dboard[i][j] });
		}
	for (int i = 0; i < 4; i++)
	{
		solve(0, i, Dboard);
	}
	if (res == INF)
	{
		res = 0;
		for (int i=0; i<n; i++)
			for (int j = 0; j < m; j++)
			{
				if (!Dboard[i][j]) res++;
			}
	}
	cout << res;
}