#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 30
int n, m;
char in[4];
int board[MAX][MAX];
bool visited[MAX];
queue <int> q;
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> in[j];
		}
		board[in[0] - 'a'][in[3] - 'a'] = 1;
		
	}
}
void solve() {
	for (int i = 0; i < MAX; i++) {
		vector <int> res;
		q.push(i);
		visited[i] = true;
		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			for (int j = 0; j < MAX; j++) {
				if (board[cur][j] == 0) continue;
				if (visited[j]) continue;
				visited[j] = true;
				res.push_back(j);
				q.push(j);
			}
		}
		for (auto j : res) {
			board[i][j] = 1;
		}
		fill(visited, visited + MAX, false);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> in[j];
		}
		if (board[in[0] - 'a'][in[3] - 'a'] == 1)
			cout << "T\n";
		else
			cout << "F\n";
	}
	return;
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	solve();
}