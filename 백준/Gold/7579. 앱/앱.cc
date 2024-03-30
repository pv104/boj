#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
#define MAX 102
int N, M, maxCost;
int weight[MAX], dp[MAX][MAX*MAX], cost[MAX];

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		cin >> weight[i];
	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
		maxCost += cost[i];
	}

}

// 모든 idx를 돌면서 dp의 값이 M인 최소 j 찾기
int solve() {
	int res = MAX*MAX;

	// dp[i][j] = max(dp[i-1][j-cost[i]]+weight[i],dp[i-1][j]);
	for (int i = 1; i <= N; i++) {

		for (int j = 0; j <= maxCost; j++) {
			if (j < cost[i]) {
				dp[i][j] = dp[i - 1][j]; 
				continue; 
			}

			dp[i][j] = max(dp[i - 1][j - cost[i]] + weight[i],
				dp[i - 1][j]);
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= maxCost; j++) {
			if (dp[i][j] >= M)
			res = min(res, j);
		}
	}
	return res;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0); input(); cout << solve();
}