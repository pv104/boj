/*백준 18808번 스티커 붙이기 */
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
vector <pair<int, int>> stickersize; // 스티커의 각 row,col 크기를 저장하는 vector

// 스티커 회전 함수
vector <vector <int>> rotate(int k, int count, int t[MAX][MAX])
{
	int row = stickersize[k].X, col = stickersize[k].Y;
	int tmp[MAX][MAX];

	for (int i = 0; i < MAX; i++)
		fill(tmp[i], tmp[i] + MAX, -1);
	for (int x = 0; x < count; x++)
	{// tmp에 스티커를 90도 회전해서 채우기
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				tmp[j][row - 1 - i] = t[i][j]; 
		for (int i = 0; i < MAX; i++)
			for (int j = 0; j < MAX; j++)
				t[i][j] = tmp[i][j]; 
		// 한번 돌리고 나서 row와 col의 위치를 바꿔야 올바르게 회전함
		swap(row, col); 
	}
	vector <vector<int>> sticker;
	vector <int> v;
	// 벡터 v는 열이므로 열의 개수만큼 크기 맞추기
		for (int i = 0; i < col; i++) 
			v.push_back(0);
		// 벡터 sticker는 2차원 배열이므로 행의 개수만큼 v를 push
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
	
	// board 전체를 탐색
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			// k번째 스티커의 행,열만큼 탐색
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
						
					// 스티커를 붙일 수 없는 경우
						if (board[i + x][j + y] == A && sticker[x][y] == A)
						{
							flag = true;
							break;
						}

					}
					if (flag) break;
				}
				if (!flag)
				{// flag = false면 붙일 수 있음
					for (int x = 0; x < sticker.size(); x++)
					{
						for (int y = 0; y < sticker[x].size(); y++)
						{
							// board에 스티커 붙이기
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
			// 최대 270도 회전 ( 0 = 0(360)도, 1 = 90도, 2 = 180도, 3 = 270도
			// 만약 attach의 값이 true라면 스티커를 붙인 경우이므로 break
			if (attach(i, count))
				break;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			// 값이 1 = 스티커가 붙은 경우
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