#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
#define MAX 100003
// idx번째에서의 왼발,오른발의 최소값
int dp[MAX][5][5]; 
int arr[MAX];
int t, idx;
void input() {
	t = 0;

	do {
		arr[idx++] = t;
		cin >> t;
		if (t == 0) break;
	} while (true);
	--idx;
	memset(dp, -1, sizeof(dp));
}
int power(int cur,int nxt) {

	if (cur == nxt) return 1;
	if (cur == 0) return 2;
	if (cur == 1 || cur == 3) {
		if (nxt == 2 || nxt == 4)
			return 3;
	}
	if (cur == 2 || cur == 4) {
		if (nxt == 1 || nxt == 3)
			return 3;
	}
	if (abs(cur - nxt) == 2) 
		return 4;
	
	return 0;
}
int rec(int cur, int x, int y) {

	if (cur == idx) {

		return 0;
	}
	if (dp[cur][x][y] != -1)
		return dp[cur][x][y];
	int t = 0;
	//cout << " DP : " << t << " cur : " << cur << " x : " << x << " y : " << y << "\n";
	t = min(rec(cur + 1, arr[cur + 1], y) + power(x, arr[cur + 1]), rec(cur + 1, x, arr[cur + 1]) + power(y,arr[cur + 1]));
	
	return dp[cur][x][y] = t;

}
int solve() {
	if (idx == 1) return 2;
	int res = rec(0, 0, 0);
	return res;
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	cout << solve();
}