#include <iostream>
#include <algorithm>
#define MAX 10003
#define CMAX 103
using namespace std;
int dp[MAX];
int coin[CMAX];
int n, k;
void input() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
}
int solve() {
	
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j - coin[i] < 0) continue;
			dp[j] += dp[j - coin[i]];
		}
	}
	return dp[k];
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	cout << solve();
}