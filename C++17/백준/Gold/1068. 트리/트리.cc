#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define MAX 52
vector<vector<int>> tree;
int N, sizes[MAX];
bool visited[MAX];
void input() {
	cin >> N;
	int x;
	tree.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> x;
		if (x == -1) continue;
		tree[x].push_back(i);
	}
}
void dfs(int cur) {

	for (auto nxt : tree[cur]) {
		if (visited[nxt]) continue;
		visited[nxt] = true;
		dfs(nxt);
	}
}
int solve() {

	int res = N;
	int x;
	cin >> x;
	visited[x] = true;
	dfs(x);
	
	for (int i = 0; i < N; i++) {
		if (visited[i]) {
			--res; continue;
		}
		int cnt = tree[i].size();
		for (auto j : tree[i]) {
			if (visited[j])
				cnt--;
		}
		tree[i].resize(cnt);
		if (tree[i].size() != 0) --res;
	}

	return res;
}
int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	input(); cout << solve();
}