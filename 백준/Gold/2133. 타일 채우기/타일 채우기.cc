#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define MAX 32
#define X first
#define Y second
#define ll long long
ll n, k, res;
ll board[MAX][MAX];
ll dp[MAX][6];
map <ll, vector<ll>> blocks = { {0,{1,3,5}} ,{1,{0,4}}, {2,{3}},{3,{0,2}},{4,{1}},{5,{0}}};
void input() {
	cin >> n;
	for (int i = 0; i < MAX; i++) {
		fill(dp[i], dp[i] + 6, -1);
	}
}
ll rec(ll idx, ll curBlock) {
	if (idx == n-1) {
		return curBlock % 2;
	}
	if (dp[idx][curBlock] != -1) return dp[idx][curBlock];
	
	auto keys = blocks[curBlock];
	ll t = 0;
	for (auto nxt : keys) {

		t += rec(idx + 1, nxt);
	}
	return dp[idx][curBlock] = t;
}
ll solve() {
	if (n % 2 == 1) return 0;
	return rec(0, 0);

	
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	cout << solve();

}