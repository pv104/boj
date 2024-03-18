#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1002
int n;
int arr[MAX], dp[MAX];
void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
}
int solve() {
	for (int k = 1; k <= n; k++) {
		dp[k] = 1; // 기본 1개
		for (int i = 1; i <= k; i++) {
			if (arr[i] < arr[k]) {
				dp[k] = max(dp[k], dp[i] + 1);
			}
		}
	}
	int res = 0;
	for (auto i : dp)
		res = max(res, i);
	return res;
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	cout << solve();
}