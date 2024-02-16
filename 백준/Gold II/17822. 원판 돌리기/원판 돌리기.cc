#include <deque>
#include <iostream>
#include<vector>
using namespace std;
#define X first
#define Y second
int n, m, t;
#define MAX 1002
vector<pair<int, int>> Counts[MAX];
int x, d, k;
const int BMAX = 55;
deque<int> board[BMAX];
int visited[BMAX][BMAX];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
void input() {
	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++) {

		for (int j = 0; j < m; j++) {
			int z;
			cin >> z;
			board[i].push_back(z);
		}
	}
}

void removes() {
	int ts = 0;
	int size = 0;
	for (auto i : board) {
		for (auto j : i) {
			ts += j;
			if (j != 0) ++size;
		}
	}
	double avg = 0;
	if(size != 0)
	avg = (double)ts / size;
	if (avg <= 0) return;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0) continue;
			if (avg < board[i][j]) {
				--board[i][j];
			}
			else if (avg > board[i][j]) {
				++board[i][j];
			}
		}
	}

}
int deletes() {

	int flags = 0;
	for (int i = 1; i < MAX; i++) {
		if (Counts[i].size() == 0) continue;
		else {
			for (auto pa : Counts[i]) {
				board[pa.X][pa.Y] = 0;
			}
			flags = 1;
		}
		Counts[i].clear();
	}

	return flags;
}
void rotate() {
	for (int i = x; i <= n; i += x) {
		if (d == 0) { // 시계
			for (int j = 0; j < k; j++) {
				board[i].push_front(board[i].back());
				board[i].pop_back();
			}
		}
		else {

			for (int j = 0; j < k; j++) {
				board[i].push_back(board[i].front());
				board[i].pop_front();
			}
		}
	}

	return;
}
void find() {
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = false;
		}
	}
	int flag = 0;
	for (int i = 1; i <= n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 0) continue;
				for (int dir=0; dir<4; dir++)
				{
					int nx = i + dx[dir];
					int ny = j + dy[dir];
					ny %= m;
					if (ny < 0) ny = m - 1;
					if (nx < 1 || ny < 0 || nx > n || ny >= m || visited[nx][ny]) continue;
					if (board[i][j] != board[nx][ny]) continue;
					int val = board[i][j];
					visited[nx][ny] = true;
					Counts[val].push_back({ i,j });
					Counts[val].push_back({ nx,ny });
				}
			}	
	}
	flag += deletes();
	if (flag == 0) removes();
}
int solve() {

	for (int tc = 0; tc < t; tc++) {
		cin >> x >> d >> k;
		rotate();
		find();
		deletes();
	
	}
	int sum = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			sum += board[i][j];
		}
	}
	return sum;
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	cout << solve();
}