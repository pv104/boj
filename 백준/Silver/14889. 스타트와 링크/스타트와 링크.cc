#include <bits/stdc++.h>
using namespace std;
#define SIZE 22
#define INF 987654321
#define fastio cin.tie(0); cin.sync_with_stdio(0)
int board[SIZE][SIZE];
int arr[SIZE][3], N, M;
int res = INF;
int visited[SIZE];
void input() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
			
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = i+1; j < N; j++)
		{
			board[i][j] += board[j][i];
			board[j][i] = 0;
		}
	}
	M = N >> 1;
}

void dfs(int cur, int cnt,int now) {

	if (cnt == M)
	{
		int s1 = 0, s2 = 0;
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (j == k) continue;
				if (visited[j] == 1 && visited[k] == 1)
					s1 += board[j][k];
				if (visited[j] == 0 && visited[k] == 0)
					s2 += board[j][k];
			}
		}
		res = min(res, abs(s1 - s2));
		return;
	}
	for (int i = cur; i < N; i++) {
		if (visited[i] > 0) continue;
		visited[i] = 1;
		dfs(i, cnt + 1, now);
		visited[i] = 0;
	}
		return;
}
int solve() {
	dfs(0, 0, 1);
	return res;
}
int main() {
	fastio;
	cin.tie(0); cin.sync_with_stdio(0);
	input(); cout << solve();
}