#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;
#define SIZE 55
#define MOD 1000007
int dp[SIZE][SIZE][SIZE][SIZE];
// (r,c,last,cnt)
int N, M, C, curC;
int board[SIZE][SIZE];
void input() {
	memset(dp, -1, sizeof(dp));
	cin >> N >> M >> C;
	int y, x;
	for (int i = 1; i <= C; i++) {
		cin >> x >> y;
		board[x][y] = i;
	}
}
int re_dp(int r, int c, int last, int cnt)
{
	if (r > N || c > M || cnt < 0) return 0;
	
	if (r == N && c == M)
	{

		if (cnt == 0)
			return 1;
		return 0;
	}
	if (dp[r][c][last][cnt] != -1) return dp[r][c][last][cnt];
	int &t = dp[r][c][last][cnt];
	t = 0;
	// 그냥 길
	if (board[r + 1][c] == 0)
	{
		t += re_dp(r + 1, c, last, cnt);
		t %= MOD;
	}
	//  오락실
	else if(board[r+1][c] != 0)
	{
		int num = board[r + 1][c];
		if (last < num) // 번호가 더 크면
		{
			t += re_dp(r + 1, c, num, cnt - 1);
			t %= MOD;
		}
	}
	if (board[r][c + 1] == 0)
	{
		t += re_dp(r, c + 1, last, cnt);
		t %= MOD;
	}
	else if(board[r][c+1] != 0)
	{
		int num = board[r][c + 1];
		if (last < num) // 번호가 더 크면
		{
			t += re_dp(r, c + 1, num, cnt - 1);
			t %= MOD;
		}
	}
	return t;
}
void solve()
{
	for (int i = 0; i <= C; i++) {

		if (board[1][1] == 0)
			cout << re_dp(1, 1, 0, i) << " ";
		else
			cout << re_dp(1, 1, board[1][1], i - 1) << " ";
	}
	return;
}
int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	input(); solve();
	return 0;
}