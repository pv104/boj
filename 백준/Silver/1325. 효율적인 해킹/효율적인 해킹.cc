#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAXN 10005
#define MAXM 100005
int a, b, n, m;
bool visited[MAXN];
vector<int> v[MAXN];
int res[MAXN];
queue <int> q;
void input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[b].push_back(a);
	}
}
void solve(vector <int>& resV) {
	int maxValue = 0;
	for (int i = 1; i < MAXN; i++) {
		if (v[i].size() < 1) continue;
		fill(visited, visited + MAXN, false);
		res[i]++;
		visited[i] = true;
		q.push(i);
		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			for (auto j : v[cur]) {
				if (visited[j]) continue;
				visited[j] = true;
				res[i]++;
				q.push(j);
			}
		}
		maxValue = max(maxValue, res[i]);
	}
	
	for (int i = 1; i <= MAXN; i++) {
		if (maxValue == res[i]) {
			resV.push_back(i);
		}
	}
	return;
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	vector<int> resV;
	solve(resV);
	for (auto i : resV) {
		cout << i << ' ';
	}
}
