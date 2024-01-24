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
		for (auto i : v[cur.second]) {
			if (dist[cur.second] + i.first < dist[i.second]) {
				dist[i.second] = dist[cur.second] + i.first;
				pq.push({ dist[i.second], i.second });
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
	string res = suc;
	if (p2 != (p1 + dist[n])) res = fail;
	
	cout << res;
}