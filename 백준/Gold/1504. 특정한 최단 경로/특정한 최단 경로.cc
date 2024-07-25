#include <iostream>
#include <queue>
#include <memory.h>
#include <vector>
using namespace std;
#define fastio cin.tie(0); cin.sync_with_stdio(0)
#define SIZE 803
#define INF 300000000
#define pii pair<int,int>
int N, M, S, E, V1, V2;
int costS[SIZE], cost1[SIZE], cost2[SIZE];
vector<pii> board[SIZE];
void init() {
	fill(costS, costS + SIZE, INF);
	fill(cost1, cost1 + SIZE, INF);
	fill(cost2, cost2 + SIZE, INF);
}
void input() {
	cin >> N >> M;
	int y, x, c;
	for (int i = 0; i < M; i++)
	{
		cin >> y >> x >> c;
		board[y].push_back({ c,x });
		board[x].push_back({ c,y });
	}

	cin >> V1 >> V2;
}
void dijkstra(int st, int* cost)
{
	cost[st] = 0;
	priority_queue <pii> pq;
	pq.push({ 0,st });

	while (!pq.empty()) {
		auto vtx = pq.top(); pq.pop();
		int val = vtx.first; // start -> cur까지의 최단거리
		int cur = vtx.second; // vertex
		if (val > cost[cur]) continue;
		for (int i = 0; i < board[cur].size(); i++) {
			int nCost = board[cur][i].first + val;
			int nxt = board[cur][i].second;
			if (nCost < cost[nxt]) // 경유하는게 더 작으면
			{
				cost[nxt] = nCost; // cost를 교체
				pq.push({ nCost,nxt });
			}
		}
	}
	return;
}
int solve() {
	S = 1, E = N;
	dijkstra(S, costS);
	dijkstra(V1, cost1);
	dijkstra(V2, cost2);

	int res = min(costS[V1] + cost1[V2] + cost2[E],
		costS[V2] + cost2[V1] + cost1[E]);

	if (res >= INF) res = -1;
	return res;
}
int main() {
	fastio;
	init();
	input();
	cout << solve();

}