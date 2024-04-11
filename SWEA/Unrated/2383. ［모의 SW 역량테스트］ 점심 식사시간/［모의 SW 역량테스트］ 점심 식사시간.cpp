#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
#define MAX 12
#define pii pair<int,int>
#define Y first
#define X second
int T, N, P, res;
int dist[MAX][2], arr[MAX], board[MAX][MAX];
pii stairs[2];
void init() {
	memset(dist, 0, sizeof(dist));
	memset(arr, 0, sizeof(arr));
	memset(board, 0, sizeof(board));
	memset(stairs, -1, sizeof(stairs));
	P = 0;
	res = 1e9;
}
void input() {
	cin >> N;
	int s1 = 0, s2 = 0;
	for (int i=0; i<N; i++)
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] > 1)
			{
				if (stairs[0].Y == -1) {
					stairs[0].Y = i;
					stairs[0].X = j;
				}
				else {
					stairs[1].Y = i;
					stairs[1].X = j;
				}
			}
		}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 1) {
				dist[P][0] = abs(stairs[0].Y - i) + abs(stairs[0].X - j);
				dist[P++][1] = abs(stairs[1].Y - i) + abs(stairs[1].X - j);
			}
		}
	}
}
void movePeople() {
	int time = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	int s1 = board[stairs[0].Y][stairs[0].X];
	int s2 = board[stairs[1].Y][stairs[1].X];
	for (int i = 0; i < P; i++) {
		
		if (arr[i] == 1) {
			
			pq.push({ dist[i][0], 1});
		}
		else {
			pq.push({ dist[i][1], 2});
		}
	}

	queue <int> q1, q2;
	while (!pq.empty()) {
		if (time > res) return;
		auto cur = pq.top(); pq.pop();
		int start = cur.Y;
		int stair = cur.X;
		if (time < start) time = start;
		if (stair == 1) {
			if (q1.size() < 3) {
				q1.push({ start + s1 + 1 });
			}
			else {
				auto q1Cur = q1.front(); q1.pop();
				if (time < q1Cur) time = q1Cur;
				if (start < q1Cur) {
					q1.push({ time + s1 });
				}
				else {
					q1.push({ time + s1 + 1 });
				}
			}
		}
		else {
			if (q2.size() < 3) {
				q2.push({ start + s2 + 1 });
			}
			else {
				auto q2Cur = q2.front(); q2.pop();
				if (time < q2Cur) time = q2Cur;
				if (start < q2Cur) {
					q2.push({ time + s2 });
				}
				else {
					q2.push({ time + s2 + 1 });
				}
			}
		}
	}

	while (!q1.empty()) {
		auto cur = q1.front(); q1.pop();
		time = max(cur, time);
	}
	while (!q2.empty()) {
		auto cur = q2.front(); q2.pop();
		time = max(cur, time);
	}

	/*cout << " arr : ";
	for (int i = 0; i < P; i++) {
		cout << i << " : " << arr[i] << " ";
	}
	cout << " time : " << time << "\n";*/
	res = min(res, time);
}
void pt(int cnt) {
	if (cnt == P) return;

	for (int i = 1; i <= 2; i++) {
		arr[cnt] = i;
		pt(cnt + 1);

		movePeople();

	}
	return;
}
int solve() {
	pt(0);
	return res;
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);

	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		init();
		input();

		cout << "#" << TC << " " << solve() << "\n";
	}
}