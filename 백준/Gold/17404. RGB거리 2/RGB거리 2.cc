#include <iostream>
using namespace std;
#define SIZE 1003
#define INF 987654321
int N, res = INF;
int arr[SIZE][3];
int dp[SIZE][3][3];
const int R = 0, G = 1, B = 2;
void input() {
	
	cin >> N;
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> arr[i][j];
		}
	}
	fill_n(&dp[0][0][0], SIZE * 3 * 3, INF);
}
int re_dp(int idx, int cur, int f)
{
	int nr = arr[idx][R];
	int ng = arr[idx][G];
	int nb = arr[idx][B];
	if (idx == N) {
		return 0;
	}
	int& t = dp[idx][cur][f];
	if (t != INF) return t;
	if (idx == 0)
	{
		t = min(t, re_dp(1, R, R) + nr);
		t = min(t, re_dp(1, G, G) + ng);
		t = min(t, re_dp(1, B, B) + nb);
	}
	if (idx > 0 && idx < N - 1)
	{
		if (cur == R)
		{
			t = min(t, re_dp(idx + 1, G, f) + ng);
			t = min(t, re_dp(idx + 1, B, f) + nb);
		}
		else if (cur == G) {

			t = min(t, re_dp(idx + 1, R, f) + nr);
			t = min(t, re_dp(idx + 1, B, f) + nb);
		}
		else {
			t = min(t, re_dp(idx + 1, R, f) + nr);
			t = min(t, re_dp(idx + 1, G, f) + ng);
		}
	}
	else if (idx == N - 1)
	{
		if (cur == R)
		{
			if (f == R)
			{
				t = min(t, re_dp(idx + 1, G, f) + ng);
				t = min(t, re_dp(idx + 1, B, f) + nb);
			}
			else if (f == G)
			{
				t = min(t, re_dp(idx + 1, B, f) + nb);
			}
			else if (f == B)
			t = min(t, re_dp(idx + 1, G, f) + ng);
		}
		else if (cur == G) {

			if (f == R)
			{
				t = min(t, re_dp(idx + 1, B, f) + nb);
			}
			else if (f == G)
			{
				t = min(t, re_dp(idx + 1, R, f) + nr);
				t = min(t, re_dp(idx + 1, B, f) + nb);
			}
			else if (f == B)
				t = min(t, re_dp(idx + 1, R, f) + nr);
		}
		else if (cur == B) {
			if (f == R)
			{
				t = min(t, re_dp(idx + 1, G, f) + ng);
			}
			else if (f == G)
			{
				t = min(t, re_dp(idx + 1, R, f) + nr);
			}
			else if (f == B)
			{
				t = min(t, re_dp(idx + 1, R, f) + nr);
				t = min(t, re_dp(idx + 1, G, f) + ng);
			}
		}
	}
	return t;
}
int solve() {
	return res = min(res, re_dp(0, 0, 0));
}
int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	input();
	cout << solve();
}