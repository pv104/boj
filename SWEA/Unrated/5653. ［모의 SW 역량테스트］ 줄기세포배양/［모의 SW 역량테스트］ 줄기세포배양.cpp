#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include<memory.h>
using namespace std;
#define MAX 800
#define CN 400
#define INF 987654321
int board[MAX][MAX];
int N, M, K;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
typedef struct cell {
	int r;
	int c;
	int hp;
	int time;
	int activeTime;
}Cell;
struct cmp {
	bool operator() (cell& a, cell& b) {
		// hp 내림차순
		// 시간이 같으면 -> HP가 큰 순
		if (a.activeTime == b.activeTime) {
			return a.hp < b.hp;
		}
		// 시간이 같지 않으면 -> 
		else if (a.activeTime != b.activeTime) {
			return a.activeTime > b.activeTime;
		}
		return a.activeTime < b.activeTime;
	}
};
priority_queue <cell, vector<cell>, cmp> pq;
queue <cell> q;
void init() {
	memset(board, 0, sizeof(board));
	while (!pq.empty())
		pq.pop();
}
void input() {
	cin >> N >> M >> K;
	for (int i = CN; i < CN + N; i++) {
		for (int j = CN; j < CN + M; j++) {
			cin >> board[i][j];
			if (board[i][j] > 0) {
				pq.push({ i,j,board[i][j],board[i][j]-1,board[i][j] }); // r,c,hp,time,activeTime;
			}
		}
	}
}
int solve() {
	int res = 0;
	int size;
	int timer = 0;

	while (++timer != K) {
		size = pq.size();
		while (size-- > 0) {
			auto cur = pq.top(); pq.pop();
			int r = cur.r;
			int c = cur.c;
			int hp = cur.hp;
			int time = cur.time;
			int activeTime = cur.activeTime;

			// 번식 가능
			if (activeTime == timer) {
				for (int dir = 0; dir < 4; dir++) {
					int nr = r + dr[dir];
					int nc = c + dc[dir];
					if (board[nr][nc] > 0) continue;
					board[nr][nc] = hp;
					pq.push({ nr,nc,hp,hp-1,hp+timer+1});
				}
				// 현재 활성화된 시간을 기록해서 큐에 push(단,1초짜리는 바로 죽으니까 push x)
				if(time > 0)
				q.push({ r,c,hp,timer + hp - 1,0 });
			}
			else {
				pq.push({ r,c,hp,time,activeTime }); continue;
			}

		}
		
	}

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		if (K <= cur.time) res++;
	}
	return pq.size() + res;
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0); 
	int T;
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		init();
		input();

		cout << "#" << TC << " " << solve() << "\n";
	}
}