#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 10003
#define CMAX 103
#define INF 987654321
using namespace std;
int dp[MAX];
vector<int> coin;
int n, k;
void input() {
	cin >> n >> k;
	int t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		coin.push_back(t);
	}
	fill(dp + 1, dp + MAX, INF);
	sort(coin.begin(), coin.end());
}
int solve() {
	
	for (int i = 1; i <= k; i++) {
		for (int j = 0, index = 0; j < n; j++) {

			if (coin[j] <= i) {
				index = i - coin[j];
				dp[i] = min(dp[i], dp[index] + 1);
			} 
		}
		
	}
	return dp[k] == INF ? -1 : dp[k];
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	cout << solve();
}