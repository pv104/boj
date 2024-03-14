#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
int n;
#define MAX 102
#define ll long long
ll dp[MAX][MAX];
int arr[MAX][MAX];

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	
	for (int i = 0; i < MAX; i++)
		fill(dp[i], dp[i] + MAX, -1);
}
ll re_dp(int r,int c) {
	if (r > n || c > n) return 0;
	if (arr[r][c] == 0) {
		if (r == n-1 && c == n-1) return 1;
		return 0;
	}

	if (dp[r][c] != -1) return dp[r][c];
	ll t = 0;
	t += re_dp(r, c + arr[r][c]);
	t += re_dp(r + arr[r][c], c);
	
	return dp[r][c] = t;
	
}
ll solve() {
	ll res = re_dp(0, 0);
	return res;
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	cout << solve();
}