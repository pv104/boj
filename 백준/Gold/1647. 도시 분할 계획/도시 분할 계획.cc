#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 100003
#define Y first
#define C second
int n, m, x, y, c;
int U[MAX];
struct str {
	int x;
	int y;
	int cost;
	str() {}
	str(int x, int y, int cost) : x(x), y(y), cost(cost) {}
};
struct cmp {
	bool operator()(const str& a, const str& b) {
		return a.cost > b.cost;
	}
};
int FIND(int a) {
	if (U[a] == a) return a;
	U[a] = FIND(U[a]);
	return U[a];
}
bool find(int a, int b) {
	a = FIND(a);
	b = FIND(b);
	if (a == b) return true;
	else {
		U[b] = a;
		return false;
	}
}
priority_queue <str, vector<str>, cmp> pq;
void input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> c;
		if (x < y) swap(x, y);
		pq.push({ x,y,c });
	}
}
int solve() {

	int res = 0;
	for (int i = 1; i <= n; i++) {
		U[i] = i;
	}
	int cnt = 0;
	while (cnt < n - 2) {
		auto cur = pq.top();
		pq.pop();
		if (!find(cur.x, cur.y)) {
			cnt++;
			res += cur.cost;
			//cout << " res : " << res << "\n";
		}
	}
	return res;
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	cout << solve();
}
