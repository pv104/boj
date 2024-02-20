#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
int a, b;
const int MAX = 32002;
vector<int> v[MAX];
queue <int> q;
bool visited[MAX];
int cnts[MAX];
void input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		--a; --b;
		v[a].push_back(b);
		++cnts[b];
	}

	for (int i = 0; i < n; i++) {

		if (cnts[i] == 0)
		{
			q.push(i);
			visited[i] = true;
		}
		
	}
}
void solve() {

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		cout << cur + 1 << " ";
		for (auto nxt : v[cur]) {
			if (visited[nxt] || cnts[nxt] < 1) continue;
			--cnts[nxt];
			if (cnts[nxt] == 0) {
				visited[nxt] = true;
				q.push(nxt);
				continue;
			}

		}
	}
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	solve();
}