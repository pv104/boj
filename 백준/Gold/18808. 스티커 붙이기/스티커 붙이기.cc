/*���� 18808�� ��ƼĿ ���̱� */
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
vector <pair<int, int>> stickersize; // ��ƼĿ�� �� row,col ũ�⸦ �����ϴ� vector

// ��ƼĿ ȸ�� �Լ�
vector <vector <int>> rotate(int k, int count, int t[MAX][MAX])
{
	int row = stickersize[k].X, col = stickersize[k].Y;
	int tmp[MAX][MAX];

	for (int i = 0; i < MAX; i++)
		fill(tmp[i], tmp[i] + MAX, -1);
	for (int x = 0; x < count; x++)
	{// tmp�� ��ƼĿ�� 90�� ȸ���ؼ� ä���
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				tmp[j][row - 1 - i] = t[i][j]; 
		for (int i = 0; i < MAX; i++)
			for (int j = 0; j < MAX; j++)
				t[i][j] = tmp[i][j]; 
		// �ѹ� ������ ���� row�� col�� ��ġ�� �ٲ�� �ùٸ��� ȸ����
		swap(row, col); 
	}
	vector <vector<int>> sticker;
	vector <int> v;
	// ���� v�� ���̹Ƿ� ���� ������ŭ ũ�� ���߱�
		for (int i = 0; i < col; i++) 
			v.push_back(0);
		// ���� sticker�� 2���� �迭�̹Ƿ� ���� ������ŭ v�� push
		for (int i = 0; i < row; i++) 
			sticker.push_back(v);
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				sticker[i][j] = t[i][j]; 
	return sticker;
}
void input()
{
	for (int k = 0; k < 102; k++)
		for (int i = 0; i < MAX; i++)
			for (int j = 0; j < MAX; j++)
				a[k][i][j] = U;
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
	vector<vector<int>> sticker;

	sticker = rotate(k, count,tsticker);
	
	// board ��ü�� Ž��
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			// k��° ��ƼĿ�� ��,����ŭ Ž��
				for (int x = 0; x < sticker.size(); x++)
				{
					for (int y = 0; y < sticker[x].size(); y++)
					{
						// OOB
							if ((i + x) >= n || (j + y) >= m)
							{
								flag = true;
								break;
							}
						
					// ��ƼĿ�� ���� �� ���� ���
						if (board[i + x][j + y] == A && sticker[x][y] == A)
						{
							flag = true;
							break;
						}

					}
					if (flag) break;
				}
				if (!flag)
				{// flag = false�� ���� �� ����
					for (int x = 0; x < sticker.size(); x++)
					{
						for (int y = 0; y < sticker[x].size(); y++)
						{
							// board�� ��ƼĿ ���̱�
							if (sticker[x][y] == UA) continue;
							board[i + x][j + y] = sticker[x][y];

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
			// �ִ� 270�� ȸ�� ( 0 = 0(360)��, 1 = 90��, 2 = 180��, 3 = 270��
			// ���� attach�� ���� true��� ��ƼĿ�� ���� ����̹Ƿ� break
			if (attach(i, count))
				break;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			// ���� 1 = ��ƼĿ�� ���� ���
			if (board[i][j] == A) res++;
		}
	}
	return res;
}
int main() 
{
	input();
	cout << solve();
	
}