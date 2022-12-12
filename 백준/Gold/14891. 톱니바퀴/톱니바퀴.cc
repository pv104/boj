#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 8
int K, res;
int board[5][MAX];
int board2[5][MAX];
string str;
void input()
{
	for (int i = 1; i <= 4; i++)
	{
		cin >> str;
		for (int j = 0; j < MAX; j++)
		{
			board[i][j] = str[j] - '0';
			board2[i][j] = board[i][j];
		}
	}

	cin >> K;

}
void rotate(int num, int dir)
{
	int tmp[MAX];
	if (dir == 1)
	{
		for (int i = 0; i < MAX; i++)
		{
			tmp[(i + 1) % MAX] = board2[num][i];
		}
	}
	else
	{
		for (int i = MAX - 1; i >= 0; i--)
		{
			if (i == 0) tmp[MAX - 1] = board2[num][i];
			else
				tmp[i - 1] = board2[num][i];
		}
	}
	for (int i = 0; i < MAX; i++)
		board2[num][i] = tmp[i];
}
void decision(int start, int dir, int* arr)
{
	bool isrotated[5] = { false,false,false,false,false };
	int rotated[5] = {};
	
	if (dir == 1)
	{
		rotate(start, 1);
		rotated[start] = 1;
	}
	else
	{
		rotate(start, -1);
		rotated[start] = -1;
	}
	isrotated[start] = true;
	for (int a = 1; a < 4; a++)
	{

		int num = arr[a];
			if (isrotated[num - 1] == true) // 왼쪽이 돌아감
			{
				if (board[num - 1][2] != board[num][6])
				{
					if (rotated[num - 1] == 1)
					{
						rotate(num, -1);
						rotated[num] = -1;
					}
					else
					{
						rotate(num, 1);
						rotated[num] = 1;
					}
					isrotated[num] = true;
				}
			}
			else if (isrotated[num+1] == true) // 오른쪽이 돌아감
			{
				if (board[num][2] != board[num + 1][6])
				{
					if (rotated[num + 1] == 1)
					{
						rotate(num, -1);
						rotated[num] = -1;
					}
					else
					{
						rotate(num, 1);
						rotated[num] = 1;
					}
					isrotated[num] = true;
				}
			}
	}
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < MAX; j++)
			board[i][j] = board2[i][j];
}
void solve()
{
	int num, dir;
	for (int count = 0; count < K; count++)
	{
		int arr[4] = {};
		cin >> num >> dir;
		// 회전할 때를 기준으로 체크
		if (num == 1)
		{
			arr[0] = 1, arr[1] = 2, arr[2] = 3, arr[3] = 4;
		}
		else if (num == 2)
		{
			arr[0] = 2, arr[1] = 1, arr[2] = 3, arr[3] = 4;
		}
		else if (num == 3)
		{
			arr[0] = 3, arr[1] = 4, arr[2] = 2, arr[3] = 1;
		}
		else
		{
			arr[0] = 4, arr[1] = 3, arr[2] = 2, arr[3] = 1;
		}
		decision(num, dir, arr);
	}
	int score = 1;
	for (int i = 1; i < 5; i++)
	{
		if (board[i][0] == 1)
		{
			res += score;
		}
		score *= 2;
	}
}

int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	solve();
	cout << res;
}