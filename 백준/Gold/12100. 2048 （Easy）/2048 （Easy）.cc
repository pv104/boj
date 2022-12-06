#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 22
int n, res;
int board[MAX][MAX];
// dir = 0 -> 위, 1 -> 오, 2 -> 아, else = 왼
void Push(vector <vector<int>>& tboard, int dir, int r, int c)
{
	if (dir == 0)
	{
		for (int i = 0; i < n; i++)
		{
			if (tboard[i][c] == 0)
			{
				for (int j = i; j < n; j++)
				{
					if (tboard[j][c] != 0)
					{
						swap(tboard[i][c], tboard[j][c]);
						break;
					}
				}
			}
		}
	}
	else if (dir == 1)
	{
		for (int i = n - 1; i >= 0; i--)
		{
			if (tboard[r][i] == 0)
			{
				for (int j = i; j >= 0; j--)
				{
					if (tboard[r][j] != 0)
					{
						swap(tboard[r][i], tboard[r][j]);
						break;
					}
				}
			}
		}
	}
	else if (dir == 2)
	{
		for (int i = n - 1; i >= 0; i--)
		{
			if (tboard[i][c] == 0)
			{
				for (int j = i; j >= 0; j--)
				{
					if (tboard[j][c] != 0)
					{
						swap(tboard[i][c], tboard[j][c]);
						break;
					}
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (tboard[r][i] == 0)
			{
				for (int j = i; j < n; j++)
				{
					if (tboard[r][j] != 0)
					{
						swap(tboard[r][i], tboard[r][j]);
						break;
					}
				}
			}
		}
	}
	return;
}
void Sum(vector <vector<int>>& tboard, int dir, int r, int c)
{
	if (dir == 0)
	{
		for (int i = 0; i < n - 1; i++)
		{
			if (tboard[i][c] == 0) continue;
			if (tboard[i][c] == tboard[i + 1][c])
			{
				tboard[i][c] *= 2;
				tboard[i + 1][c] = 0;
			}
		}
	Push(tboard, dir, r, c);
	}
	else if (dir == 1)
	{
		for (int i = n - 1; i > 0; i--)
		{
			if (tboard[r][i] == 0) continue;
			if (tboard[r][i] == tboard[r][i - 1])
			{
				tboard[r][i] *= 2;
				tboard[r][i - 1] = 0;
			}
		}
		Push(tboard, dir, r, c);
	}
	else if (dir == 2)
	{
		for (int i = n - 1; i > 0; i--)
		{
			if (tboard[i][c] == 0) continue;
			if (tboard[i][c] == tboard[i - 1][c])
			{
				tboard[i][c] *= 2;
				tboard[i - 1][c] = 0;
			}
		}
		Push(tboard, dir, r, c);
	}
	else
	{
		for (int i = 0; i < n - 1; i++)
		{
			if (tboard[r][i] == 0) continue;
			if (tboard[r][i] == tboard[r][i + 1])
			{
				tboard[r][i] *= 2;
				tboard[r][i + 1] = 0;
			}
		}
		Push(tboard, dir, r, c);
	}
	return;
}

void solve(vector <vector<int>> tboard, int cnt, int start)
{
	vector <vector<int>> v;
	vector <int> vv(n);
	for (int i = 0; i < n; i++)
		v.push_back(vv);
	if (cnt == 5)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				res = max(res, tboard[i][j]);

		return;
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				v[j][k] = tboard[j][k];

		if (i == 0) // 위, r 움직이고 c 고정
		{
			for (int j = 0; j < n; j++)
			{
				 Push(v, i, 0, j);
				 Sum(v, i, 0, j);
			}
		}
		else if (i == 1) // 오, r 고정하고 c 움직임
		{
			for (int j = n - 1; j >= 0; j--)
			{
				 Push(v, i, j, 0);
				 Sum(v, i, j, 0);
			}
		}
		else if (i == 2) // 아래, r 움직이고 c 고정
		{
			for (int j = n - 1; j >= 0; j--)
			{
				 Push(v, i, 0, j);
				 Sum(v, i, 0, j);
			}

		}
		else // 왼쪽, r 고정하고 c 움직임
		{
			for (int j = 0; j < n; j++)
			{
				 Push(v, i, j, 0);
				 Sum(v, i, j, 0);
			}

		}
		solve(v, cnt + 1, i);
	}
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	vector <vector<int>> tboard(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			tboard[i].push_back(0); 
	for (int k = 0; k < 4; k++)
	{

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				tboard[i][j] = board[i][j];

		solve(tboard, 0, k);
	}

	cout << res;
}