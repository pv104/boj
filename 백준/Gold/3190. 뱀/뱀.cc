#include <iostream>
#include <deque>
#include <queue>
#include <vector>
using namespace std;
#define MAX 102
int n, k, l;
int curR = 0;
queue <pair<int, char>> R; // 회전
deque <pair<int, int>> S; // 뱀
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
char board[MAX][MAX];
void input() {
	cin >> n >> k;
	int r, c;
	S.push_back({ 1,1 });
	for (int i = 0; i < k; i++) {
		cin >> r >> c;
		board[r][c] = 'A';
	}
	cin >> l;
	int t;
	char x;
	for (int i = 0; i < l; i++) {
		cin >> t >> x;
		R.push({ t,x });
	}
}
int solve() {
	int res = 0;
	int nx = 1;
	int ny = 1;
	for (int timer = 1; ; timer++) {
		nx += dx[curR];
		ny += dy[curR];
		S.push_back({ nx,ny }); // 뱀 길이 늘리기


		if (nx < 1 || ny < 1 || nx > n || ny > n) { // 벽
			return timer;
		}
		for (int i = 0; i < S.size() - 1; i++) {
			if (S[i].first == nx && S[i].second == ny) return timer;

		}

		if (board[nx][ny] != 'A') {
			S.pop_front();
		}
		else {
			board[nx][ny] = ' ';
		}
		if (!R.empty() && (R.front().first == timer)) { // 방향 변환
			if (R.front().second == 'D') {
				curR++;
			}
			else {
				curR--;
			}
			if (curR < 0) curR = 3;
			if (curR > 3) curR = 0;
			R.pop();
		}

	}
	return res;
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	cout << solve();
}