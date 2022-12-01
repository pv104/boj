#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 12
#define BMAX 42
#define X first
#define Y second
#define U -1
#define UA 0
#define A 1
int a[102][MAX][MAX], board[BMAX][BMAX];
int n, m, r, c, stickercount;
vector <pair<int, int>> stickersize;
vector <vector <int>> rotate(int k, int count, int t[MAX][MAX])
{
	int row = 0, col = 0;

	row = stickersize[k].X;
	col = stickersize[k].Y;

	int tmp[MAX][MAX];
	for (int i = 0; i < MAX; i++)
		fill(tmp[i], tmp[i] + MAX, -1);
	int m, min;
	m = max(row, col);
	min = (row > col) ? col : row;

	int ttt[MAX][MAX];
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			ttt[i][j] = t[i][j];

	for (int x = 0; x < count; x++)
	{
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				tmp[j][row - 1 - i] = t[i][j];
		for (int i = 0; i < MAX; i++)
			for (int j = 0; j < MAX; j++)
				t[i][j] = tmp[i][j];

		swap(row, col);
	}


	vector <vector<int>> a;
	vector <int> v;

	
		for (int i = 0; i < col; i++)
			v.push_back(0);
		for (int i = 0; i < row; i++)
			a.push_back(v);
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				a[i][j] = t[i][j];
	
	/*else
	{
		for (int i = 0; i < row; i++)
			v.push_back(0);
		for (int i = 0; i < col; i++)
			a.push_back(v);
		for (int i = 0; i < col; i++)
			for (int j = 0; j < row; j++)
				a[i][j] = t[i][j];
	}*/
	/*else if (count == 1)
	{

		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				a[i][j] = t[i][j + m - min];

	}
	else if (count == 2)
	{
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				a[i][j] = t[i + m - min][j];
	}
	else
	{
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				a[i][j] = t[i][j];
	}*/

	return a;
}
void input()
{
	for (int k = 0; k < 102; k++)
		for (int i = 0; i < MAX; i++)
			for (int j = 0; j < MAX; j++)
				a[k][i][j] = -1;
	cin >> n >> m >> stickercount;
	for (int z = 0; z < stickercount; z++)
	{
		cin >> r >> c;
		stickersize.push_back({ r,c });
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cin >> a[z][i][j];
			}
		}
		
	}

}

bool attach(int k,int count)
{
	int tsticker[MAX][MAX];
	bool flag = false;
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			tsticker[i][j] = a[k][i][j];
	vector<vector<int>> a;

	a = rotate(k, count,tsticker);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{

				for (int x = 0; x < a.size(); x++)
				{
					for (int y = 0; y < a[x].size(); y++)
					{
						
							if ((i + x) >= n || (j + y) >= m)
							{
								flag = true;
								break;
							}
						
					
						if (board[i + x][j + y] == A && a[x][y] == A)
						{
							flag = true;
							break;
						}

					}
					if (flag) break;
				}
				if (!flag)
				{
					for (int x = 0; x < a.size(); x++)
					{
						for (int y = 0; y < a[x].size(); y++)
						{
							if (a[x][y] == UA) continue;
							board[i + x][j + y] = a[x][y];
						}
					}return true;
				}
				else
				{
					flag = false;
				}
			
		}
	}

	return false;
}
int solve()
{
	int res = 0;
	for (int i = 0; i < stickercount; i++)
	{
		for (int count = 0; count < 4; count++)
		{
			if (attach(i, count))
				break;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 1) res++;
		}
	}
	return res;
}
int main() 
{
	input();
	cout << solve();
	
}