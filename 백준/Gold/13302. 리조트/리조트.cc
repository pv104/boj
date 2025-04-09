#include <iostream>
using namespace std;
#define SIZE 103
#define K 50
int dp[SIZE][K];
constexpr int INF = 987654321;
int ticket[4] = { INF, 10000, 25000, 37000};
int N, M;
bool vis[SIZE];

void input() {
	fill(&dp[0][0], &dp[0][0] + SIZE * K , INF);
	cin >> N >> M;
	int t;
	for (int i = 0; i < M; i++) {
		cin >> t;
		vis[t] = true;
	}
}
int rec(int cur, int coupon) {
	if (cur > N) return 0;
	int& t = dp[cur][coupon];
	if (t != INF) return t;

	if (vis[cur]) return t = rec(cur +1, coupon);
	
	if (coupon >= 3) 
	t = min(t, rec(cur +1, coupon - 3));
	
	t = min(t, rec(cur +1, coupon) + ticket[1]);
		
	t = min(t,rec(cur +3, coupon + 1) + ticket[2]);

	t = min(t, rec(cur +5, coupon + 2) + ticket[3]);
	
	return t;
}
int solve() {
	return rec(1, 0);
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	cout << solve();
}