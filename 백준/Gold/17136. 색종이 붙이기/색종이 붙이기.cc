#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 10
#define INF 987654321
typedef struct Paper {
	int x;
	int y;
	int size;
}Paper;
int boards[MAX][MAX];
vector <int> papers(6);
int n = 10;
int res = INF;
bool check(Paper paper);
int input() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> boards[i][j];
			if (boards[i][j] == 1) ++cnt;
		}
	}
	return cnt;
}
bool check(Paper paper) {
	int x = paper.x;
	int y = paper.y;
	int size = paper.size;

	int tx = x + size;
	int ty = y + size;
	if (tx > n || ty > n) return false;
	for (int r = x; r < tx; r++) {

		for (int c = y; c < ty; c++) {

			if (boards[r][c] != 1) return false;
		}
	}
	return true;
}
int paste(Paper paper, bool flag) {
	int x = paper.x;
	int y = paper.y;
	int size = paper.size;

	int tx = x + size;
	int ty = y + size;
	if (flag == true) {

		int cnt = 0;
		if (!check(paper)) return INF;
		for (int r = x; r < tx; r++) {

			for (int c = y; c < ty; c++) {

				boards[r][c] = 2;
				++cnt;
			}
		}

		return cnt;
	}
	else {
		for (int r = x; r < tx; r++) {

			for (int c = y; c < ty; c++) {

				boards[r][c] = 1;
			}
		}
		return 1; 
		
	}
}
int findCounts(int cnt, int paperCounts, int colorCounts) {
	if (cnt > 25) return INF;
	if (res <= cnt) return INF;
	if (paperCounts == 0) {
		return cnt;
	}
	if (colorCounts == 0) return INF;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (boards[i][j] != 1) continue;

			int size = 6;
			while (--size > 0) {
				if (papers[size] == 0) continue;
				int flag = paste({ i,j,size }, true);
				if (flag == INF) continue;
				--papers[size];
				res = min(res, findCounts(cnt + 1, paperCounts - flag, colorCounts - 1));
				++papers[size];
				paste({ i,j,size }, false);

			}
			return res;
		}
	}
	return res;
}

int solve(int paperCounts) {
	for (int i = 1; i <= 5; i++) {
		papers[i] = 5;
	}
	findCounts( 0, paperCounts, 25);
	return (res == INF) ? -1 : res;
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int paperCounts = input();
	if (paperCounts == 0) {
		cout << 0;
	}
	else cout << solve(paperCounts);
}