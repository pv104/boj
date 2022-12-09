#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define INF 987654321
#define NMAX 52
#define MMAX 15
#define X first
#define Y second
int n, m, res;
vector <pair<int, int>> house, chicken;
int board[NMAX][NMAX];
int distResult[NMAX][MMAX];
int arr[MMAX];
void input()
{
	cin >> n >> m;
	for (int i=0; i<n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 1)
				house.push_back({ i,j });
			else if (board[i][j] == 2)
				chicken.push_back({ i,j });
		}
}
// 모든 집에 대한 치킨집의 거리 계산하기
void distCal()
{
	int x, y, r;
	for (int i=0; i<house.size(); i++)
		for (int j = 0; j < chicken.size(); j++)
		{
			x = house[i].X - chicken[j].X;
			if (x < 0) x = -x;
			y = house[i].Y - chicken[j].Y;
			if (y < 0) y = -y;
			r = x + y;
			if (r < 0) r = -r;
			distResult[i][j] = r;
		} 
}

void solve()
{
	// combination에서 뽑아진 조합에 대해서 각 치킨 거리가 가장 작은 집을 뽑기
	int t = 0;
	for (int i = 0; i < house.size(); i++)
	{
		int minVal = INF;
		for (int j = 0; j < m; j++)
		{
			if (minVal > distResult[i][arr[j]])
				minVal = distResult[i][arr[j]];
		}
		t += minVal;
	}
	if (res > t)
		res = t;
	return;
}
void combination(int cnt, int start)
{
	if (cnt == m)
	{
		solve();
		return;
	}
	for (int i = start; i < chicken.size(); i++)
	{
		arr[cnt] = i;
		combination(cnt + 1, i + 1);
	}
	return;
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	res = INF;
	input();
	distCal();
	combination(0, 0);
	solve();
	cout << res;
}

