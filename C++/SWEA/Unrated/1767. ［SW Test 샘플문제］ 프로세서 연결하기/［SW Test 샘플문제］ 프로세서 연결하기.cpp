#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
#define Y first
#define X second
#define pii pair<int,int>
#define SIZE 15
int N, K, T, maxCnt,maxLen;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int board[SIZE][SIZE];
vector <pii> cores;
void init() {
	maxCnt = 0, maxLen = 0;
	cores.clear();
	memset(board, 0, sizeof(board));
}
void input() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			cin >> board[i][j];
			if (i == 1 || j == 1 || i == N || j == N) continue;
			if (board[i][j] == 0) continue;
			cores.push_back({ i,j });
		}
	K = cores.size();
}
int putCable(int idx, int dir, int val) {
	int cnt = 0;
	int y = cores[idx].Y;
	int x = cores[idx].X;
	int ny = y;
	int nx = x;
	if (val == -1)
	{
		while (true) {
			ny += dy[dir];
			nx += dx[dir];
			// 다 놓은거랑, 가다가 못놓은거랑 구분하기
			// 잘 놓고 OOB
			if (ny < 1 || nx < 1 || ny > N || nx > N) return cnt;
			// 못 놓는 곳에 도착
			if (board[ny][nx] != 0) break;
			board[ny][nx] = -1;
			cnt++;
		}
		ny = y;
		nx = x;
		while (cnt--) {
			ny += dy[dir];
			nx += dx[dir];
			if (ny < 1 || nx < 1 || ny > N || nx > N) return 0;
			if (board[ny][nx] != -1) break;
			board[ny][nx] = 0;
		}
	}
	else
	{
		while (true) {
			ny += dy[dir];
			nx += dx[dir];
			if (ny < 1 || nx < 1 || ny > N || nx > N) return 0;
			if (board[ny][nx] != -1) break;
			board[ny][nx] = 0;
		}
	}
	return 0;
}
void dfs(int idx, int cnt, int len) {
	if (idx == K) {
		if (cnt == maxCnt)
		{
			maxLen = min(len, maxLen);
		}
		else if (cnt > maxCnt) {
			maxLen = len;
			maxCnt = cnt;
		}
		//cout << " cnt : " << cnt << " maxCnt : " << maxCnt << " len : " << len << " maxLen : " << maxLen << "\n";
		return;
	}
	if ((K - idx + cnt) < maxCnt) return;

	for (int dir = 0; dir < 4; dir++) {

		int t = putCable(idx, dir, -1);
		// 연결됨
		if (t != 0)
		{
			dfs(idx + 1, cnt + 1, len + t);
			putCable(idx, dir, 0);
			//cout << " i : " << idx << " dir : " << dir << " l + t : " << len + t << "\n";
		}
			dfs(idx + 1, cnt, len);
	}
	return;
}
int solve() {
	dfs(0, 0, 0);
	return maxLen;
}
int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	/*FILE* stream;
	freopen_s(&stream, "input.txt", "r", stdin);
	freopen_s(&stream, "output.txt", "w", stdout);*/

	cin >> T;
	for (int TC = 1; TC <= T; TC++)
	{
		init();
		input();
		cout << "#" << TC << " " << solve() << "\n";
	}
}