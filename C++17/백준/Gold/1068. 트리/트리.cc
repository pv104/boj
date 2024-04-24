#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> tree;
int N, K, x, root = 0;
void input() {
	cin >> N;
	tree.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> x;
		if (x == -1) {
			root = i;
			continue;
		}
		tree[x].push_back(i);
	}
	cin >> K;
}
int rec(int cur) {
	int cnt = 0;
	if (cur == K) return 0;
	if (tree[cur].empty()) return 1;
	for (auto nxt : tree[cur]) 
		cnt += rec(nxt);
	if (cnt == 0) ++cnt;
	return cnt;
}
int solve() {
	int res = rec(root);
	return res;
}
int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	input(); cout << solve();
}