#include <iostream>
#include <string>
#include <queue>
#include <memory.h>
using namespace std;
#define fastio cin.tie(0); cin.sync_with_stdio(0)
#define Y first
#define X second
#define SIZE 1005
#define INF (int)1e9<<1
int N, M, S, E;
int board[SIZE][SIZE], dist[SIZE];
struct T
{
	int s;
	int e;
	int c;
	T() {}
	T(int s, int e, int c) {
		this->s = s;
		this->e = e;
		this->c = c;
	}
};
struct cmp {
	bool operator()(T a, T b) {
		if (a.c < b.c) {
			return a.c > b.c;
		}
		return a.c < b.c;
	}
};
priority_queue < T, vector<T>, cmp> pq;
void init() {

	fill(dist, dist + SIZE, INF);
	memset(board, -1, sizeof(board));
	dist[S] = 0;
}
void input() {
	cin >> N >> M;
	int y, x, c;
	for (int i = 0; i < M; i++)
	{
		cin >> y >> x >> c;
		board[y][x] = (board[y][x] == -1 || board[y][x] > c) ? c : board[y][x];
	}
	cin >> S >> E;
	for (int i = 1; i <= N; i++) {

		if (board[S][i] < 0) continue;
		pq.push({ S,i,board[S][i] });
		dist[i] = board[S][i];
		
	}
}
int solve() {
	int res = 0;

	if (S == E) return 0;
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		int s = cur.s;
		int e = cur.e;
		int c = cur.c;
		for (int j = 1; j <= N; j++) {
			int nxt = board[e][j];
			if (nxt == -1) continue;
			if (dist[j] > c + nxt)
			{
				dist[j] = c + nxt;
				pq.push({ e,j,c + nxt });
			}
		}
	}

	return res = dist[E];
}
int main() {
	fastio;

	init();
	input();
	cout << solve();

}