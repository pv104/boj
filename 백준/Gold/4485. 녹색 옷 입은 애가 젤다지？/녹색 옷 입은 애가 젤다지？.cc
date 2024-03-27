#include <iostream>
#include <queue>
using namespace std;
#define INF 987654321
#define MAX 128
int n;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int board[MAX][MAX], dist[MAX][MAX];
void input(int t){
	n = t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			dist[i][j] = INF;
		}
	}
}
typedef struct Pairs {
int x;
int y;
int val;
Pairs() {}
Pairs(int x, int y, int val) {
	this->x = x;
	this->y = y;
	this->val = val;
}
}Pairs;
typedef struct compare {
	bool operator()(const Pairs& o1, const Pairs& o2) {
		return o1.val > o2.val;
	}
}cp;
priority_queue<Pairs,vector<Pairs>,cp> pq;
int solve(){
pq.push({ 0, 0, board[0][0] });
dist[0][0] = board[0][0];
while (!pq.empty()) {
	Pairs cur = pq.top();
	pq.pop();
	int r = cur.x;
	int c = cur.y;
	if (r == n - 1 && c == n - 1) {
		return dist[r][c];
	}
	for (int dir = 0; dir < 4; dir++) {
		int nr = r + dx[dir];
		int nc = c + dy[dir];
		if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
		if (dist[nr][nc] > dist[r][c] + board[nr][nc]) {
			dist[nr][nc] = dist[r][c] + board[nr][nc];
			pq.push({ nr, nc, dist[nr][nc] });
		}
	}
}
return 0;
}

int main() {
	int t = 1, counts = 1;
	cin.tie(0); ios::sync_with_stdio(0);
	while (true) {
		cin >> t;
		if (t == 0) break;
		input(t);
		cout << "Problem " << counts++ << ": " << solve() << "\n";
	}
}