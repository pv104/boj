#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 5
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
char dat[MAX][MAX];
bool vis[MAX][MAX];
bool Select[MAX][MAX];
int res;
int arr[7];
stack <pair<int, int>> s;

int DFS()
{
	int cnt = 1;
	while (!s.empty())
	{

		auto cur = s.top(); s.pop();
		int x = cur.first;
		int y = cur.second;
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = dx[dir] + x;
			int ny = dy[dir] + y;

			if (nx < 0 || ny < 0 || nx >= MAX || ny >= MAX || vis[nx][ny]) continue;
			if (!Select[nx][ny]) continue;
			vis[nx][ny] = true;
			s.push({nx,ny });
			cnt++;
		}
	}

	return cnt;
}
void Combination(int k, int start)
{
	if (k == 7)
	{
		int ycnt = 0;
		for (int i = 0; i < 7; i++) {
			
			if (dat[arr[i] / 5][arr[i] % 5] == 'Y') ycnt++;
		}
		if (ycnt < 4)
		{
			for (int i=0; i<7; i++)
				Select[arr[i] / 5][arr[i] % 5] = true;
			s.push({ arr[0]/5,arr[0]%5});
			vis[arr[0] / 5][arr[0] % 5] = true;
			if (DFS() == 7) res++;

			for (int i = 0; i < MAX; i++)

			{
				fill(vis[i], vis[i] + MAX, false);
				fill(Select[i], Select[i] + MAX, false);
			}
		}
		return;
	}

	for (int i = start; i < MAX * MAX; i++)
	{
		arr[k] = i;
		Combination(k + 1, i + 1);
	}
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			cin >> dat[i][j];
	for (int i = 0; i < MAX; i++)
		fill(Select[i], Select[i] + MAX, false);

	Combination(0, 0);
	cout << res;
}