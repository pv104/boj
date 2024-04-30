#pragma warning(disable: 4996)
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define SIZE 500002
#define Y first
#define P second
#define pii pair<int,int>
int N, W, U, V;
bool visited[SIZE];
double weights[SIZE];
vector <vector<int>> tree(SIZE);
queue <int> q;
void input() {
	scanf("%d %d", &N, &W);
	for (int i = 1; i < N; i++) {
		scanf("%d %d", &U, &V);
		tree[U].push_back(V);
		tree[V].push_back(U);
	}
	weights[1] = W;

}
double bfs() {

	// 해당 정점의 모든 자식에 대해 먼저 물을 주고, 큐에 push
	// 다음으로 큐에서 하나 꺼내기
	double val;
		int size;
	while (!q.empty()) {

		int cur = q.front(); q.pop();
		//cout << " w[cur] : " << weights[cur] << "\n";
		size = tree[cur].size();
		for (auto nxt : tree[cur]) {
			if (visited[nxt])
				size--;
		}
		if (size == 0) continue;
		val = weights[cur] / size;
		weights[cur] = 0;
		for (auto nxt : tree[cur]) {
			if (visited[nxt]) continue;
			weights[nxt] += val;
			visited[nxt] = true;
			q.push(nxt);
		}
	}

	double res;
	int cnt;
	cnt = res = 0;

	for (int i = 0; i < SIZE; i++) {
		if (weights[i] == 0) continue;
		cnt++;
		res += weights[i];
	}

	return res / cnt;
}
double solve() {
	double avg;
	int res, cnt;
	avg = res = cnt = 0;
	q.push(1);
	visited[1] = true;
	avg = bfs();

	return avg;
	
}
int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	input(); printf("%.10lf", solve());
}