#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define INF 987654321
#define MAX 5003
int vtx, p, n, m;
const string suc = "SAVE HIM";
const string fail = "GOOD BYE";
priority_queue <pair<int, int>> pq;
vector < pair<int, int> >v[MAX];
int dist[MAX];
void init(int x) {
	fill(dist, dist + MAX, INF);
	dist[x] = 0;
	for (auto i : v[x]) {
		pq.push(i);
		dist[i.second] = i.first;
	}
}
void input() {
	cin >> n >> m >> p;
	int x, y, d;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> d;
		v[x].push_back({ d,y });
		v[y].push_back({ d,x });
	}
}
void solve() {
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		int curVertex = cur.second;
		if (cur.first < dist[curVertex]) continue;
		for (auto nxt : v[cur.second]) {
			int nxtVertex = nxt.second;
			int nxtCost = nxt.first;
			if (dist[curVertex] + nxtCost < dist[nxtVertex]) {
				dist[nxtVertex] = dist[curVertex] + nxtCost;
				pq.push({ dist[nxtVertex], nxtVertex });
			}
		}
	}
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	init(1);
	solve();
	int p1 = dist[p], p2 = dist[n];
	init(p);
	solve();
	string res = fail;
	if (p2 == (p1 + dist[n])) res = suc;

	cout << res;
}