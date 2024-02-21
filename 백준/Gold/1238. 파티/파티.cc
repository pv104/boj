#include <iostream>
#include <vector>
#include <queue>
#define W first
#define C second
using namespace std;
int n, m, x;
int r, c, w;
const int MAX = 1002;
const int INF = 987654321;
vector<pair<int,int>> v[MAX];
priority_queue <pair<int,int>, vector <pair<int,int>>, greater<pair<int, int>>> q;
int toCost[MAX];
int endCost[MAX];
void input() {
	cin >> n >> m >> x;
	--x;
	for (int i = 0; i < m; i++) {
		cin >> r >> c >> w;
		--r; --c;
		// v[r][c] = w, 우선순위용 w 먼저
		v[r].push_back({w,c});
		
	}

}
/// <summary>
/// 1. x->최단경로 찾기
/// 2. 다른 모든 정점에서 x로 가는 최단경로 찾기
/// 3. 1->x+x->1, 2->x+x->2...의 max 구하기
/// </summary>

void toFind(int index) {

	fill(toCost, toCost + MAX, INF);
	toCost[index] = 0;
	q.push({ 0,index });
	while (!q.empty()) {
		auto cur = q.top(); q.pop();
		int dist = cur.first; //현재 노드까지의 비용
		int now = cur.second;
		if (toCost[now] < dist) continue;
		int size = v[now].size();
		for (int i = 0; i < size; i++) {
			int cost = dist + v[now][i].first;
			int nxt = v[now][i].second;

			if (cost < toCost[nxt]) {
				toCost[nxt] = cost;
				q.push({ cost,nxt });
			}
		}
	}
}
void endFind() {
	fill(endCost, endCost + MAX, INF);
	endCost[x] = 0;
	q.push({ 0,x });
	while (!q.empty()) {
		auto cur = q.top(); q.pop();
		int dist = cur.first; //현재 노드까지의 비용
		int now = cur.second;
		if (endCost[now] < dist) continue;
		int size = v[now].size();
		for (int i = 0; i < size; i++) {
			int cost = dist + v[now][i].first;
			int nxt = v[now][i].second;

			if (cost < endCost[nxt]) {
				endCost[nxt] = cost;
				q.push({ cost,nxt });
			}
		}
	}
}
int solve() {
	endFind(); // x에서 시작하는 경로 찾기
	int res = 0;
	for (int index = 0; index < n; index++) {
		if (x == index) continue;
		toFind(index);
		res = max(res, toCost[x] + endCost[index]); 
	}
	return res;
	
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	cout << solve();
}